// Hole.h
#ifndef HOLE_H
#define HOLE_H

#include "GameItem.h"
#include "Player.h"
// Look at me using abstract base classes
class Hole : public GameItem {
public:
    Hole(int x, int y, int cellSize);
    void interact(Player* player) override;
};

#endif // HOLE_H
