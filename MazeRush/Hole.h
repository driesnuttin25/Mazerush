// Hole.h
#ifndef HOLE_H
#define HOLE_H

#include "GameItem.h"
#include "Player.h"

// Hole class: Inherits from GameItem, represents holes in the maze
class Hole : public GameItem {
public:
    Hole(int x, int y, int cellSize); // Constructor to initialize a hole at a position with a size
    void interact(Player* player) override; // Defines interaction with the player
};

#endif // HOLE_H
