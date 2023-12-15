#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include "Maze.h"
#include "Player.h"
#include <QTimer>
#include <QLabel>

class MazeView : public QGraphicsView {
    Q_OBJECT

public:
    MazeView(Maze* maze, Player* player, int cellSize, QWidget* parent = nullptr);
    void updateCoinDisplay(int coins);
    void addCoinGraphic();
    void resetTimer();

    void drawMaze();
    void setMaze(Maze* newMaze);
private:
    Player* player;
    Maze* maze;
    int cellSize;
    std::vector<QGraphicsPixmapItem*> coinGraphics; // Container for coin graphics
    int mazeHeight; // Height of the maze in cells
    QTimer* gameTimer; // Timer for the game duration
    QLabel* timerLabel; // Label to display the remaining time
    int remainingTime = 60; // 60 seconds total time

private slots:
    void updateTimer();

};

#endif // MAZEVIEW_H
