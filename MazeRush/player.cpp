// Player.cpp
#include "Player.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent), stepSize(10), playerSize(20, 20) {
    // Set the starting position and size of the player
    setRect(0, 0, playerSize.width(), playerSize.height());
    qDebug() << "Player size after setRect:" << rect().size();

    // Set the brush to fill the rectangle
    QBrush brush(Qt::blue);  // Player color
    setBrush(brush);

    // Set the initial position
    setPos(1, 1);  // Starting position at (1,1) in the maze
}

QSizeF Player::getPlayerSize() const {
    return playerSize;
}

void Player::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Key pressed:" << event->key();

    int dx = 0;
    int dy = 0;
    switch (event->key()) {
    case Qt::Key_Left:
        dx = -stepSize;
        qDebug() << "Attempting to move left";
        break;
    case Qt::Key_Right:
        dx = stepSize;
        qDebug() << "Attempting to move right";
        break;
    case Qt::Key_Up:
        dy = -stepSize;
        qDebug() << "Attempting to move up";
        break;
    case Qt::Key_Down:
        dy = stepSize;
        qDebug() << "Attempting to move down";
        break;
    default:
        QGraphicsRectItem::keyPressEvent(event);
        return;
    }

    // Calculate the new position and check for potential collisions
    QPointF newPos = pos() + QPointF(dx, dy);

    // Use a smaller rectangle for collision detection to provide "padding" around the player
    QRectF smallerRect = rect().adjusted(5, 5, -5, -5);
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
