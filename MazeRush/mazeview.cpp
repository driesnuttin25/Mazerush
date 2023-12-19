#include "MazeView.h"
#include "Chest.h"
#include "Hole.h"
#include "Player.h"
#include "qapplication.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>

// Constructor
MazeView::MazeView(Maze* maze, Player* player, int cellSize, QWidget* parent)
    : QGraphicsView(parent), player(player), maze(maze), cellSize(cellSize) {
    qDebug() << "MazeView Constructor called";
    QGraphicsScene* newScene = new QGraphicsScene(this);
    setScene(newScene); // Set the scene for the view
    mazeHeight = maze->height;
    drawMaze(); // Draw the maze
    gameTimer = new QTimer(this); // Initialize game timer
    connect(gameTimer, &QTimer::timeout, this, &MazeView::updateTimer);
    gameTimer->start(1000); // Start timer with a 1-second interval
    timerLabel = new QLabel(this); // Initialize timer label
    timerLabel->setGeometry(10, 10, 100, 30); // Set label position and size
    updateTimer(); // Update timer display
}

// Function to draw the maze
void MazeView::drawMaze() {
    setBackgroundBrush(QBrush(Qt::gray)); // Set background color for the maze
    if (!maze) return; // Check if maze is set
    auto layout = maze->getLayout(); // Get maze layout
    QPixmap wallTexture(":/assets/wall.png"); // Load wall texture

    for (size_t y = 0; y < layout.size(); ++y) {
        for (size_t x = 0; x < layout[y].size(); ++x) {
            // Place holes, chests, and walls based on the maze layout
            if (layout[y][x] == 3) { // If cell is a hole
                Hole* hole = new Hole(x, y, cellSize);
                scene()->addItem(hole); // Add hole to the scene
            } else if (layout[y][x] == 2) { // If cell is a chest
                Chest* chest = new Chest(player, this, x, y, cellSize);
                scene()->addItem(chest); // Add chest to the scene
            } else if (layout[y][x] == 1) { // If cell is a wall
                QGraphicsPixmapItem* wall = new QGraphicsPixmapItem(wallTexture);
                wall->setPos(x * cellSize, y * cellSize); // Position the wall
                wall->setScale(static_cast<double>(cellSize) / wallTexture.width()); // Scale wall to fit cell
                scene()->addItem(wall); // Add wall to the scene
            }
        }
    }
}

// Function to add a coin graphic
void MazeView::addCoinGraphic() {
    QPixmap coinPixmap(":/assets/cheese.png"); // Load coin image
    int coinSize = 40; // Define coin size
    QPixmap scaledCoinPixmap = coinPixmap.scaled(coinSize, coinSize, Qt::KeepAspectRatio); // Scale coin image
    QGraphicsPixmapItem* newCoin = new QGraphicsPixmapItem(scaledCoinPixmap); // Create coin pixmap item
    int coinXPosition = coinGraphics.size() * coinSize; // Calculate X position for the new coin
    int coinYPosition = mazeHeight * cellSize - 40; // Calculate Y position for the new coin
    newCoin->setPos(coinXPosition, coinYPosition); // Set coin position
    scene()->addItem(newCoin); // Add coin to the scene
    coinGraphics.push_back(newCoin); // Store coin in the vector
}

// Function to set a new maze
void MazeView::setMaze(Maze* newMaze) {
    maze = newMaze; // Update maze pointer
    drawMaze(); // Redraw the maze
}

// Function to update the game timer
void MazeView::updateTimer() {
    if (remainingTime > 0) {
        remainingTime--; // Decrement remaining time
        timerLabel->setText("Time: " + QString::number(remainingTime)); // Update timer label
    } else {
        gameTimer->stop(); // Stop the timer
        QApplication::quit(); // Quit the application when time runs out
    }
}

// Function to reset the game timer
void MazeView::resetTimer() {
    remainingTime = 60; // Reset the timer to 60 seconds
    updateTimer(); // Update the timer display
    gameTimer->start(1000); // Restart the timer
}
