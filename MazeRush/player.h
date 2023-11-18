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

public slots:
    void move();

private:
    float stepSize;
    QSizeF playerSize;
    QTimer* moveTimer;
    QSet<int> pressedKeys; // Store pressed keys
};

#endif // PLAYER_H
