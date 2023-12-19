// Player.cpp
#include "Player.h"
#include "GameConfig.h"
#include "GameItem.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>

// Constructor: Initializes the player with its properties and sprites
Player::Player(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), stepSize(3), playerSize(20, 20) {
    // Load the player sprites for different directions
    spriteUp = QPixmap(":/assets/mouse_up.png");
    spriteDown = QPixmap(":/assets/mouse_down.png");
    spriteLeft = QPixmap(":/assets/mouse_left.png");
    spriteRight = QPixmap(":/assets/mouse_right.png");

    // Set the initial sprite and position in the maze
    setPixmap(spriteUp.scaled(playerSize.toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(1, 1);

    // Load player speed setting from a configuration file
    GameConfig config("C:/Users/dries/OneDrive/Music/Documents/TcXaeShell/Tc2_DMX_Sample_DMX_Master/Desktop/Cpp/MazeRush/config.ini");
    int playerSpeed = config.get("player_speed");

    // Initialize and start the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Player::move);
    moveTimer->start(playerSpeed);

    // Enable the player to receive key events
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

// Handle key press events to determine player's direction
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

// Handle key release events and update the player's direction
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

        // Iterate through colliding items
        for (auto* item : collidingItems) {
            if (item != this) {
                if (GameItem* gameItem = dynamic_cast<GameItem*>(item)) {
                    // If the colliding item is a GameItem, trigger interact and continue movement
                    gameItem->interact(this);
                } else {
                    // If it's not a GameItem, block the movement
                    qDebug() << "Movement blocked by collision with non-interactable item";
                    return;  // Stop the move function if collision with non-interactable item
                }
            }
        }

        // Move the player to the new position
        setPos(newPos);
        qDebug() << "Moved to:" << newPos;
    }
}

// Adds a coin to the player's total and checks for level completion
void Player::addCoin() {
    coins++;
    qDebug() << "Coin added. Total coins:" << coins;
    if (coins == 9) {  // Assuming you have a constant or variable for this
        qDebug() << "All coins collected. Level completed.";
        level_complete = true;
        emit levelCompleted();
    }
}




// Returns the total number of coins collected
int Player::getCoins() const {
    return coins;
}


void Player::resetState() {
    setPos(1, 1); // Reset position
    coins = 0;    // Reset coins
    // Any other state reset needed
}
