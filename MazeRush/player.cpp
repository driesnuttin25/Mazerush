// Player.cpp
#include "Player.h"
#include "Chest.h"
#include "GameItem.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

bool keyHeld = false;

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent), stepSize(3), playerSize(20, 20) {
    qDebug() << "Player Constructor called";
    // Player position and height!
    setRect(0, 0, playerSize.width(), playerSize.height());
    qDebug() << "Player size after setRect:" << rect().size();

    QBrush brush(Qt::blue);  // Player color
    setBrush(brush);

    // Initialize the timer
    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    // Set the initial position
    setPos(1, 1);   // Starting position at (1,1) in the maze

    // Make the player focusable to receive key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (!pressedKeys.contains(event->key())) {
        pressedKeys.insert(event->key()); // Add the key to the set of pressed keys
        if (!moveTimer->isActive()) {
            moveTimer->start(15); // Check that this line is correctly executed
        }
    }
    event->accept();
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    pressedKeys.remove(event->key()); // Remove the key from the set
    if (pressedKeys.isEmpty() && moveTimer->isActive()) {
        moveTimer->stop(); // This should only stop the timer if no keys are pressed
    }
    event->accept();
}



QSizeF Player::getPlayerSize() const {
    return playerSize;
}


void Player::move() {
    qDebug() << "Move method called";

    int dx = 0;
    int dy = 0;
    if (pressedKeys.contains(Qt::Key_Left)) dx -= stepSize;
    if (pressedKeys.contains(Qt::Key_Right)) dx += stepSize;
    if (pressedKeys.contains(Qt::Key_Up)) dy -= stepSize;
    if (pressedKeys.contains(Qt::Key_Down)) dy += stepSize;

    QPointF newPos = pos() + QPointF(dx, dy);
    QRectF smallerRect = rect().adjusted(2, 2, -2, -2);
    QList<QGraphicsItem*> itemsAtNewPos = scene()->items(QRectF(newPos + smallerRect.topLeft(), smallerRect.size()));

    bool collisionDetected = false;

    for (QGraphicsItem* item : itemsAtNewPos) {
        if (item != this) {
            GameItem* gameItem = dynamic_cast<GameItem*>(item);
            if (gameItem) {
                gameItem->interact(this);
                continue;
            } else {
                collisionDetected = true;
                break;
            }
        }
    }

    if (!collisionDetected) {
        setPos(newPos);
        qDebug() << "Moved to:" << newPos;
    } else {
        qDebug() << "Movement blocked by collision";
    }
}


void Player::addCoin() {
    coins++;
    qDebug() << "Coin added. Total coins:" << coins;
    if (coins == 5) {  // Assuming you have a constant or variable for this
        qDebug() << "All coins collected. Level completed.";
        emit levelCompleted();
    }
}




int Player::getCoins() const {
    return coins;
}


void Player::resetState() {
    setPos(1, 1); // Reset position
    coins = 0;    // Reset coins
    // Any other state reset needed
}
