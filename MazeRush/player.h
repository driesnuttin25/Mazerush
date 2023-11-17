// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player : public QGraphicsRectItem {
public:
    Player(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    QSizeF getPlayerSize() const;

private:
    int stepSize;
    QSizeF playerSize; // Add a member variable for player size
};

#endif // PLAYER_H
