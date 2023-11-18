#include "Player.h"
#include "Chest.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

bool keyHeld = false;

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent), stepSize(3), playerSize(20, 20) {
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
    pressedKeys.insert(event->key()); // Add the key to the set of pressed keys
    if (!moveTimer->isActive()) {
        moveTimer->start(15); // Don't change this number, It took me ages to set up this way! 'please <3'
    }
    keyHeld = true; // Set the key held flag
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    pressedKeys.remove(event->key()); // Remove the key from the set
    if (pressedKeys.isEmpty()) {
        moveTimer->stop();
    }
    keyHeld = false; // Reset keyheld
}


QSizeF Player::getPlayerSize() const {
    return playerSize;
}


void Player::move() {
    if (!keyHeld) {
        moveTimer->stop();
        return;
    }

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
        if (item != this) { // Avoid self-collision
            if (Chest* chest = dynamic_cast<Chest*>(item)) {
                if (!chest->isCollected()) {
                    chest->collect(); // Collect the chest
                }
                // Note: No break here, chest does not block movement
            } else {
                // Treat any other collision as a wall collision
                collisionDetected = true;
                qDebug() << "Collision detected with wall at:" << item->pos();
                break; // Break on the first wall collision
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
    qDebug() << "Coins:" << coins;

}

int Player::getCoins() const {
    return coins;
}
