// MazeView.h
#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include "Maze.h"
#include "Player.h"
#include <QTimer>
#include <QLabel>

// MazeView class: Manages the graphical view and interactions of the maze
class MazeView : public QGraphicsView {
    Q_OBJECT

public:
    MazeView(Maze* maze, Player* player, int cellSize, QWidget* parent = nullptr); // Constructor to initialize MazeView
    void updateCoinDisplay(int coins); // Updates the coin count display
    void addCoinGraphic(); // Adds a graphical representation of a coin
    void resetTimer(); // Resets the game timer
    void drawMaze(); // Draws the maze on the screen
    void setMaze(Maze* newMaze); // Sets a new maze for the view

private:
    Player* player; // Reference to the player
    Maze* maze; // Reference to the maze
    int cellSize; // Size of each cell in the maze
    std::vector<QGraphicsPixmapItem*> coinGraphics; // Container for coin graphics
    int mazeHeight; // Height of the maze in cells
    QTimer* gameTimer; // Timer for the game
    QLabel* timerLabel; // Label for displaying remaining time
    int remainingTime = 60; // Total game time (60 seconds)

private slots:
    void updateTimer(); // Slot to update the timer periodically

};

#endif // MAZEVIEW_H
