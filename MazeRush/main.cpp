#include <QApplication>
#include "TitleScreen.h"
#include "Maze.h"
#include "MazeView.h"
#include "Player.h"

// Function to start the game
void startGame(MazeView** view, Maze** maze, Player** player, int mazeWidth, int mazeHeight, int cellSize) {
    if (*maze != nullptr) {
        delete *maze;
    }
    if (*player != nullptr) {
        delete *player;
    }
    if (*view != nullptr) {
        delete *view;
    }

    *maze = new Maze(mazeWidth, mazeHeight); // Maze object
    *player = new Player();

    *view = new MazeView(*maze, *player, cellSize);
    (*view)->scene()->addItem(*player);
    (*player)->setPos(cellSize, cellSize);

    (*view)->show();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int mazeWidth = 19; // Width of the maze in cells
    int mazeHeight = 19; // Height of the maze in cells
    int cellSize = 50; // Size of each cell in pixels

    TitleScreen titleScreen;
    MazeView* view = nullptr;
    Maze* maze = nullptr;
    Player* player = nullptr;

    QObject::connect(&titleScreen, &TitleScreen::startGame, [&](){
        startGame(&view, &maze, &player, mazeWidth, mazeHeight, cellSize);
        titleScreen.hide();
    });

    titleScreen.show();

    return app.exec();
}
