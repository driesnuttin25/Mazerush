#include "Player.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

bool keyHeld = false;

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent), stepSize(3), playerSize(20, 20) {
    // Set the starting position and size of the player
    setRect(0, 0, playerSize.width(), playerSize.height());
    qDebug() << "Player size after setRect:" << rect().size();

    // Set the brush to fill the rectangle
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
        moveTimer->start(15); // Adjust the interval as needed for smooth movement
    }
    keyHeld = true; // Set the key held flag
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    pressedKeys.remove(event->key()); // Remove the key from the set
    if (pressedKeys.isEmpty()) {
        moveTimer->stop();
    }
    keyHeld = false; // Clear the key held flag
}


QSizeF Player::getPlayerSize() const {
    return playerSize;
}


void Player::move() {
    if (!keyHeld) {
        // Stop moving if the key has been released
        moveTimer->stop();
        return;
    }
    int dx = 0;
    int dy = 0;
    if (pressedKeys.contains(Qt::Key_Left)) dx -= stepSize;
    if (pressedKeys.contains(Qt::Key_Right)) dx += stepSize;
    if (pressedKeys.contains(Qt::Key_Up)) dy -= stepSize;
    if (pressedKeys.contains(Qt::Key_Down)) dy += stepSize;

    // Calculate the new position and check for potential collisions
    QPointF newPos = pos() + QPointF(dx, dy);

    // Use a smaller rectangle for collision detection to provide "padding" around the player
    QRectF smallerRect = rect().adjusted(2, 2, -2, -2);
    QList<QGraphicsItem *> itemsAtNewPos = scene()->items(QRectF(newPos + smallerRect.topLeft(), smallerRect.size()));

    // Check for collisions
    bool collisionDetected = false;
    for (QGraphicsItem *item : itemsAtNewPos) {
        if (item != this && item->collidesWithItem(this)) {
            collisionDetected = true;
            qDebug() << "Collision detected with item at:" << item->pos();
            break;
        }
    }

    // Move player if no collision is detected
    if (!collisionDetected) {
        setPos(newPos);
        qDebug() << "Moved to:" << newPos;
    } else {
        qDebug() << "Movement blocked by collision";
    }
}
