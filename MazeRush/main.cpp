// main.cpp
#include <QApplication>
#include "Maze.h"
#include "MazeView.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int mazeWidth = 201; // Width of the maze in cells
    int mazeHeight = 201; // Height of the maze in cells
    int cellSize = 5; // Size of each cell in pixels

    qDebug() << "Creating maze with dimensions:" << mazeWidth << mazeHeight;
    Maze maze(mazeWidth, mazeHeight);
    MazeView view(maze, cellSize);

    qDebug() << "Showing view.";
    view.show();

    qDebug() << "Starting application.";
    return app.exec();
}
