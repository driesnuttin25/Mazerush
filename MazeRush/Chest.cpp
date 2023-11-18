// Chest.cpp
#include "Chest.h"
#include "qgraphicsscene.h"
#include <QPixmap>

Chest::Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize)
    : player(player), mazeView(mazeView) {
    QPixmap originalPixmap(":/assets/chest.png");
    QPixmap scaledPixmap = originalPixmap.scaled(cellSize-20, cellSize-20, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);
    setPos(x * cellSize, y * cellSize);
    collected = false;
}

bool Chest::isCollected() const {
    return collected;
}

void Chest::interact(Player* player) {
    if (!collected) {
        collected = true;
        hide(); // Hide the chest

        QPixmap originalCoinPixmap(":/assets/coin.png");
        int coinSize = 30; // Set the desired size for the coin
        QPixmap scaledCoinPixmap = originalCoinPixmap.scaled(coinSize, coinSize, Qt::KeepAspectRatio);

        QGraphicsPixmapItem* coin = new QGraphicsPixmapItem(scaledCoinPixmap);
        coin->setPos(pos()); // Position the coin where the chest was
        scene()->addItem(coin);

        QTimer::singleShot(500, [coin](){
            if (coin->scene()) {
                coin->scene()->removeItem(coin);
            }
            delete coin;
        });

        if (player) {
            player->addCoin();
            if (mazeView) { // Check if mazeView is not null
                mazeView->addCoinGraphic();
            }
        }
    }
}

