// GameItem.h
#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "Player.h"
#include <QGraphicsPixmapItem>

// GameItem class: Abstract base class for interactive items in the game
class GameItem : public QGraphicsPixmapItem {
public:
    virtual void interact(Player* player) = 0; // Pure virtual function for interaction
};

#endif // GAMEITEM_H
