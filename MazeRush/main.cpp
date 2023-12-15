#include <QApplication>
#include "TitleScreen.h"
#include "GameConfig.h"
#include "Maze.h"
#include "MazeView.h"
#include "Player.h"

void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player) {
    qDebug() << "Starting new game level:" << currentLevel;

    // Clear the scene if it exists, but do not delete the view
    if (view) {
        view->scene()->clear();
    }

    // Reset and reuse the existing Maze and Player objects
    if (!maze) {
        maze = new Maze(mazeWidth, mazeHeight);
    } else {
        maze->reset(mazeWidth, mazeHeight); // Add a reset method to Maze class
    }

    if (!player) {
        player = new Player();
    } else {
        player->resetState(); // Reset player's state for the new level
    }

    if (!view) {
        view = new MazeView(maze, player, cellSize);
    } else {
        view->setMaze(maze); // Add a method in MazeView to update the maze reference
        view->drawMaze();    // Redraw the maze
    }

    // Update connections and scene
    QObject::disconnect(player, &Player::levelCompleted, nullptr, nullptr);
    QObject::connect(player, &Player::levelCompleted, [  cellSize, &currentLevel, &view, &maze, &player]() mutable {
        currentLevel++;
        int newWidth = 7 + 2 * (currentLevel - 1);
        int newHeight = newWidth;
        startGame(newWidth, newHeight, cellSize, currentLevel, view, maze, player);
    });

    view->scene()->addItem(player); // Re-add player to the scene
    player->setPos(cellSize, cellSize);
    view->show();
}




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Application started";

    GameConfig config("C:/Users/dries/OneDrive/Music/Documents/TcXaeShell/Tc2_DMX_Sample_DMX_Master/Desktop/Cpp/MazeRush/config.ini");

    int initialMazeWidth = config.get("maze_width");
    int initialMazeHeight = config.get("maze_height");
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
