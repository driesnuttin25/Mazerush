// Player.cpp
#include "Player.h"
#include "GameConfig.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent), stepSize(3), playerSize(20, 20) {
    // Load the sprites
    spriteUp = QPixmap(":/assets/mouse_up.png");
    spriteDown = QPixmap(":/assets/mouse_down.png");
    spriteLeft = QPixmap(":/assets/mouse_left.png");
    spriteRight = QPixmap(":/assets/mouse_right.png");

    // Set the initial sprite and size
    setPixmap(spriteUp.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(1, 1); // Starting position at (1,1) in the maze

    GameConfig config("C:/Users/dries/OneDrive/Music/Documents/TcXaeShell/Tc2_DMX_Sample_DMX_Master/Desktop/Cpp/MazeRush/config.ini");
    int playerSpeed = config.get("player_speed");

    // Initialize the timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Player::move);
    moveTimer->start(playerSpeed); // Start the timer with a 15ms interval

    // Make the player focusable to receive key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}


void Player::updateSprite(const QString &direction) {
    if (direction == "up") {
        setPixmap(spriteUp.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else if (direction == "down") {
        setPixmap(spriteDown.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else if (direction == "left") {
        setPixmap(spriteLeft.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else if (direction == "right") {
        setPixmap(spriteRight.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (!pressedKeys.contains(event->key())) {
        pressedKeys.insert(event->key()); // Add the key to the set of pressed keys
        switch (event->key()) {
        case Qt::Key_Up:
            currentDirection = Direction::Up;
            updateSprite("up");
            break;
        case Qt::Key_Down:
            currentDirection = Direction::Down;
            updateSprite("down");
            break;
        case Qt::Key_Left:
            currentDirection = Direction::Left;
            updateSprite("left");
            break;
        case Qt::Key_Right:
            currentDirection = Direction::Right;
            updateSprite("right");
            break;
        default:
            break;
        }
    }
    event->accept();
}


void Player::keyReleaseEvent(QKeyEvent *event) {
    pressedKeys.remove(event->key()); // Remove the key from the set
    if (pressedKeys.isEmpty()) {
        currentDirection = Direction::None;
    } else {
        // Update direction and sprite based on the remaining pressed keys, if any
        if (pressedKeys.contains(Qt::Key_Up)) {
            currentDirection = Direction::Up;
            updateSprite("up");
        } else if (pressedKeys.contains(Qt::Key_Down)) {
            currentDirection = Direction::Down;
            updateSprite("down");
        } else if (pressedKeys.contains(Qt::Key_Left)) {
            currentDirection = Direction::Left;
            updateSprite("left");
        } else if (pressedKeys.contains(Qt::Key_Right)) {
            currentDirection = Direction::Right;
            updateSprite("right");
        }
    }
    event->accept();
}




void Player::move() {
    //qDebug() << "Move method called";

    // Initialize movement deltas
    int dx = 0;
    int dy = 0;

    // Update the player's sprite and movement based on the key press
    switch (currentDirection) {
    case Direction::Up:
        dy = -stepSize;
        break;
    case Direction::Down:
        dy = stepSize;
        break;
    case Direction::Left:
        dx = -stepSize;
        break;
    case Direction::Right:
        dx = stepSize;
        break;
    default:
        break;
    }

    // Calculate the new position
    QPointF newPos = pos() + QPointF(dx, dy);

    // Check collision only if there's a movement
    if (dx != 0 || dy != 0) {
        QList<QGraphicsItem*> collidingItems = scene()->items(QRectF(newPos, playerSize.toSize()));
        bool collisionDetected = std::any_of(collidingItems.begin(), collidingItems.end(), [this](QGraphicsItem* item) {
            return item != this && typeid(*item) != typeid(Player);
        });

        if (!collisionDetected) {
            setPos(newPos);
            qDebug() << "Moved to:" << newPos;
        } else {
            qDebug() << "Movement blocked by collision";
        }
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
