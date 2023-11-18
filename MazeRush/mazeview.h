// MazeView.h
#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include "Maze.h"
#include "Player.h"

class MazeView : public QGraphicsView {
public:
    MazeView(Maze* maze, Player* player, int cellSize, QWidget* parent = nullptr);
    void updateCoinDisplay(int coins);
    void addCoinGraphic();

private:
    Player* player;
    const Maze& maze;
    int cellSize;
    std::vector<QGraphicsPixmapItem*> coinGraphics; // Container for coin graphics
    int mazeHeight; // Height of the maze in cells
    void drawMaze();
};

#endif // MAZEVIEW_H
