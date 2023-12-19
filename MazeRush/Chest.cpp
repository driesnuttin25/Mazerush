#include "Chest.h"
#include <QPixmap>

// Constructor for Chest class
Chest::Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize)
    : player(player), mazeView(mazeView) {
    // Load and scale the chest image
    QPixmap originalPixmap(":/assets/chest.png");
    QPixmap scaledPixmap = originalPixmap.scaled(cellSize-20, cellSize-20, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);
    setPos(x * cellSize, y * cellSize); // Set chest position
    collected = false; // Initialize as not collected
}

// Check if the chest has been collected
bool Chest::isCollected() const {
    return collected;
}

// Defines interaction behavior when the player encounters a chest
void Chest::interact(Player* player) {
    if (!collected) {
        collected = true;
        hide(); // Hide the chest after it's collected

        // Still a work in progress as it does not work correctly
        /*
        QPixmap originalPixmap(":/assets/cheese.png");
        int coinSize = 30; // Size for the coin graphic
        QPixmap scaledCoinPixmap = originalPixmap.scaled(coinSize, coinSize, Qt::KeepAspectRatio);
        QGraphicsPixmapItem* coin = new QGraphicsPixmapItem(scaledCoinPixmap);
        coin->setPos(pos()); // Position the coin at the chest's location
        scene()->addItem(coin);
        QTimer::singleShot(500, [coin](){
            if (coin->scene()) {
                coin->scene()->removeItem(coin);
            }
            delete coin;
        });
        */

        if (player) {
            player->addCoin(); // Add a coin to the player's count
            qDebug() << "Chest collected, coin added"; // Debug output
            if (mazeView) {
                mazeView->addCoinGraphic(); // Update the coin graphic in the maze view
            }
        }
    } else {
        qDebug() << "Chest already collected"; // Debug output for already collected chest
    }
}
