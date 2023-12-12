#include <QApplication>
#include "TitleScreen.h"
#include "Maze.h"
#include "MazeView.h"
#include "Player.h"

void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player) {
    qDebug() << "Starting new game level:" << currentLevel;

    if (view != nullptr) {
        if (player && view->scene() == player->scene()) {
            view->scene()->removeItem(player); // Explicitly remove player from the scene
        }
        delete view;
        view = nullptr;
    }

    delete maze; // Safe to delete as nullptr deletion is a no-op

    // If player exists, reset its state, otherwise create a new player
    if (player != nullptr) {
        player->resetState(); // Reset player's state for the new level
    } else {
        player = new Player();
    }

    maze = new Maze(mazeWidth, mazeHeight);
    view = new MazeView(maze, player, cellSize);
    qDebug() << "Maze and Mazeview completed";

    QObject::disconnect(player, &Player::levelCompleted, nullptr, nullptr); // Disconnect previous connections
    QObject::connect(player, &Player::levelCompleted, [mazeWidth, mazeHeight, cellSize, &currentLevel, &view, &maze, &player]() mutable {
        qDebug() << "Level completed, moving to next level";
        currentLevel++;
        int newWidth = 7 + 2 * (currentLevel - 1);
        int newHeight = newWidth;
        startGame(newWidth, newHeight, cellSize, currentLevel, view, maze, player);
    });
    qDebug() << "Re-adding player to maze";
    view->scene()->addItem(player); // Re-add player to the scene
    qDebug() << "Player in";
    player->setPos(cellSize, cellSize); // Ensure player's position is reset
    qDebug() << "Player position check done";
    view->show();
    qDebug() << "View shown";
}



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Application started";

    int initialMazeWidth = 7;
    int initialMazeHeight = 7;
    int cellSize = 50;
    int currentLevel = 1;

    MazeView* view = nullptr;
    Maze* maze = nullptr;
    Player* player = nullptr;

    TitleScreen titleScreen;
    QObject::connect(&titleScreen, &TitleScreen::startGame, [&](){
        qDebug() << "Start game signal received";
        startGame(initialMazeWidth, initialMazeHeight, cellSize, currentLevel, view, maze, player);
        titleScreen.hide();
    });

    titleScreen.show();
    qDebug() << "Title screen shown";
    return app.exec();
}
