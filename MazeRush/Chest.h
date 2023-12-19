// Chest.h
#ifndef CHEST_H
#define CHEST_H

#include "Player.h"
#include "GameItem.h"
#include "MazeView.h"
#include <QGraphicsPixmapItem>

// Chest class: Inherits from GameItem, represents collectible chests in the game
class Chest : public GameItem {
public:
    Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize); // Constructor
    bool isCollected() const; // Check if chest is collected
    void interact(Player* player) override; // Interaction with player

private:
    bool collected; // Indicates if chest is collected
    Player* player; // Reference to player
    MazeView* mazeView; // Reference to MazeView for graphical interaction
};

#endif // CHEST_H
