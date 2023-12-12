// MazeView.cpp
#include "MazeView.h"
#include "Chest.h"
#include "Hole.h"
#include "Player.h"
#include "qapplication.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>


MazeView::MazeView(Maze* maze, Player* player, int cellSize, QWidget* parent)
    : QGraphicsView(parent), player(player), maze(*maze), cellSize(cellSize) {
    qDebug() << "MazeView Constructor called";
    // Initialize the scene
    QGraphicsScene* newScene = new QGraphicsScene(this);
    this->setScene(newScene);
    this->mazeHeight = maze->height;
    drawMaze(); // Now draw the maze
    qDebug() << "DrawMaze completed";
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MazeView::updateTimer);
    gameTimer->start(1000); // Timer ticks every second

    timerLabel = new QLabel(this);
    timerLabel->setGeometry(10, 10, 100, 30); // Set position and size of the label
    updateTimer(); // Initialize the timer display
    qDebug() << "Timer setup completed";
}

void MazeView::drawMaze() {
    // Set the background color
    setBackgroundBrush(QBrush(Qt::gray));

    auto layout = maze.getLayout();
    qDebug() << "Drawing maze with layout size:" << layout.size();

    if (!this->scene()) {
        qDebug() << "Error: Scene not initialized!";
        return;
    }

    QPixmap wallTexture(":/assets/wall.png"); // Load the wall texture

    for (size_t y = 0; y < layout.size(); ++y) {
        for (size_t x = 0; x < layout[y].size(); ++x) {
            if (layout[y][x] == 3) { // Check for hole
                Hole* hole = new Hole(x, y, cellSize);
                this->scene()->addItem(hole);
                qDebug() << "Added hole";
            }
            if (layout[y][x] == 2) { // Check for chest
                Chest* chest = new Chest(player, this, x, y, cellSize);
                this->scene()->addItem(chest);
                qDebug() << "Added Chest";
            }
            if (layout[y][x] == 1) { // Wall
                QGraphicsPixmapItem* wall = new QGraphicsPixmapItem(wallTexture);
                wall->setPos(x * cellSize, y * cellSize);
                wall->setScale(static_cast<double>(cellSize) / wallTexture.width()); // Optional: Scale to fit cell size
                this->scene()->addItem(wall);
                qDebug() << "Wall at:" << x << y;
            }
        }
    }

    qDebug() << "Maze drawing completed.";
}

void MazeView::addCoinGraphic() {
    QPixmap coinPixmap(":/assets/coin.png");
    int coinSize = 40; // Size of the coin graphic
    QPixmap scaledCoinPixmap = coinPixmap.scaled(coinSize, coinSize, Qt::KeepAspectRatio);

    QGraphicsPixmapItem* newCoin = new QGraphicsPixmapItem(scaledCoinPixmap);
    int coinXPosition = coinGraphics.size() * coinSize; // Position each coin to the right of the previous one
    int coinYPosition = mazeHeight * cellSize; // Position at the bottom of the maze
    newCoin->setPos(coinXPosition, coinYPosition - 40);
    scene()->addItem(newCoin);

    coinGraphics.push_back(newCoin); // Add to the list of coin graphics
}

void MazeView::updateTimer() {
    if (remainingTime > 0) {
        remainingTime--;
        timerLabel->setText("Time: " + QString::number(remainingTime));
    } else {
        gameTimer->stop();
        QApplication::quit(); // End the game
    }
}

void MazeView::resetTimer() {
    remainingTime = 60; // Reset to 60 seconds
    updateTimer(); // Update the timer display
    gameTimer->start(1000); // Restart the timer
}
