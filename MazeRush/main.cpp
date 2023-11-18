// main.cpp
#include <QApplication>
#include "Maze.h"
#include "MazeView.h"
#include "Player.h" // Include the Player header
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int mazeWidth = 9; // Width of the maze in cells
    int mazeHeight = 9; // Height of the maze in cells
    int cellSize = 50; // Size of each cell in pixels

    qDebug() << "Creating maze with dimensions:" << mazeWidth << mazeHeight;

    Maze maze(mazeWidth, mazeHeight); // Maze object
    Player* player = new Player();

    MazeView view(&maze, player, cellSize);
    view.scene()->addItem(player);
    player->setPos(cellSize, cellSize);

    qDebug() << "Showing view.";
    view.show();

    qDebug() << "Starting application.";
    return app.exec();
}
