#ifndef CHEST_H
#define CHEST_H

#include "Player.h"
#include "GameItem.h"
#include "MazeView.h" // Include MazeView header
#include <QGraphicsPixmapItem>

class Chest : public GameItem {
public:
    Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize);
    bool isCollected() const;
    void interact(Player* player) override;

private:
    bool collected;
    Player* player;
    MazeView* mazeView; // Declare MazeView pointer
};

#endif // CHEST_H
