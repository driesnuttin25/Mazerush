// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QSet>

// Direction enum: Represents possible movement directions of the player
enum class Direction : unsigned char {
    None = 0,
    Up,
    Down,
    Left,
    Right
};

// Player class: Manages the player's interactions and movement in the game
class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = nullptr); // Constructor for Player
    QSizeF getPlayerSize() const; // Returns the player's size
    int getCoins() const; // Returns the number of coins the player has
    void keyPressEvent(QKeyEvent *event) override; // Handles key press events
    void keyReleaseEvent(QKeyEvent *event) override; // Handles key release events
    void addCoin(); // Adds a coin to the player's total
    void resetState(); // Resets the player's state
    void updateSprite(const QString &direction); // Updates the player's sprite based on direction
    bool keyHeld = false; // Flag to check if a key is held down

public slots:
    void move(); // Slot to handle player movement

signals:
    void chestCollected(int x, int y); // Signal when a chest is collected
    void levelCompleted(); // Signal when the level is completed

private:
    float stepSize; // Step size for player movement
    unsigned char coins = 0; // Number of coins collected
    QSizeF playerSize; // Size of the player
    QTimer* moveTimer; // Timer for player movement
    QSet<int> pressedKeys; // Set of currently pressed keys
    QPixmap spriteUp; // Player's sprite for moving up
    QPixmap spriteDown; // Player's sprite for moving down
    QPixmap spriteLeft; // Player's sprite for moving left
    QPixmap spriteRight; // Player's sprite for moving right
    Direction currentDirection = Direction::None; // Current direction of the player
};

#endif // PLAYER_H
