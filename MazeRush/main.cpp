#include <QApplication>
#include "TitleScreen.h"
#include "GameConfig.h"
#include "Maze.h"
#include "MazeView.h"
#include "Player.h"

void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player) {
    qDebug() << "Starting new game level:" << currentLevel;

    // Delete and reset existing objects if they exist
    if (view) {
        view->scene()->clear();
        delete view;
        view = nullptr;
    }

    if (maze) {
        delete maze;
        maze = nullptr;
    }

    if (player) {
        delete player;
        player = nullptr;
    }

    // Create new instances of Maze, Player, and MazeView
    maze = new Maze(mazeWidth, mazeHeight);
    player = new Player();
    view = new MazeView(maze, player, cellSize);

    // Setup the MazeView and its scene
    view->setMaze(maze);
    view->drawMaze();
    view->scene()->addItem(player);
    player->setPos(cellSize, cellSize); // Set initial player position
    view->show();

    // Connect the levelCompleted signal to start a new level
    QObject::disconnect(player, &Player::levelCompleted, nullptr, nullptr);
    QObject::connect(player, &Player::levelCompleted, [&mazeWidth, &mazeHeight, cellSize, &currentLevel, &view, &maze, &player]() mutable {
        currentLevel++;
        int newWidth = 7 + 2 * (currentLevel - 1);
        int newHeight = newWidth;
        startGame(newWidth, newHeight, cellSize, currentLevel, view, maze, player);
    });
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
