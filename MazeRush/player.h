#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QSet>

// If Direction enum is specific to Player, include it inside the Player class.
// Otherwise, declare it outside if it's used by other classes too.
enum class Direction : unsigned char {
    None = 0,
    Up,
    Down,
    Left,
    Right
};

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QSizeF getPlayerSize() const;

    void addCoin();
    int getCoins() const;

    void resetState();
    void updateSprite(const QString &direction);
    bool keyHeld = false;
public slots:
    void move();

signals:
    void chestCollected(int x, int y);
    void levelCompleted();

private:
    float stepSize;
    QSizeF playerSize;
    QTimer* moveTimer;
    QSet<int> pressedKeys;
    unsigned char coins = 0;

    QPixmap spriteUp;
    QPixmap spriteDown;
    QPixmap spriteLeft;
    QPixmap spriteRight;

    Direction currentDirection = Direction::None;
};

#endif // PLAYER_H
