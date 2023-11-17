// MazeView.h
#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include "Maze.h"

class MazeView : public QGraphicsView {
public:
    MazeView(const Maze& maze, int cellSize, QWidget* parent = nullptr);

private:
    const Maze& maze;
    int cellSize;

    void drawMaze();
};

#endif // MAZEVIEW_H
