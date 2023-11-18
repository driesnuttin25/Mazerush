// GameItem.h
#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "Player.h"
#include <QGraphicsPixmapItem>

class GameItem : public QGraphicsPixmapItem {
public:
    virtual void interact(Player* player) = 0; // Pure virtual function
};

#endif // GAMEITEM_H
