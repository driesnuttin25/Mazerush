// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QSet>

class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QSizeF getPlayerSize() const;

    void addCoin();
    int getCoins() const;

    int currentLevel = 1;
    void resetState();
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
    int coins = 0;

};

#endif // PLAYER_H
