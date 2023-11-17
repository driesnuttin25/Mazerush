// MazeView.cpp
#include "MazeView.h"
#include <QGraphicsRectItem>
#include <QBrush>

MazeView::MazeView(const Maze& maze, int cellSize, QWidget* parent)
    : QGraphicsView(parent), maze(maze), cellSize(cellSize) {
    // Initialize the scene
    QGraphicsScene* newScene = new QGraphicsScene(this);
    this->setScene(newScene);
    drawMaze(); // Now draw the maze
}

void MazeView::drawMaze() {
    auto layout = maze.getLayout();
    qDebug() << "Drawing maze with layout size:" << layout.size();

    // Check if the scene is properly initialized
    if (!this->scene()) {
        qDebug() << "Error: Scene not initialized!";
        return;
    }
    for (size_t y = 0; y < layout.size(); ++y) {
        for (size_t x = 0; x < layout[y].size(); ++x) {
            if (layout[y][x] == 1) { // Wall
                QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, cellSize, cellSize);
                rect->setPos(x * cellSize, y * cellSize);
                QBrush brush(Qt::darkGreen); // Wall color
                rect->setBrush(brush);
                this->scene()->addItem(rect);
                qDebug() << "Wall at:" << x << y;
            }
        }
    }
    qDebug() << "Maze drawing completed.";
}
