#ifndef CHEST_H
#define CHEST_H

#include "Player.h"
#include "mazeview.h"
#include <QGraphicsPixmapItem>

class Chest : public QGraphicsPixmapItem {
public:
    Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize);
    bool isCollected() const;
    void collect(); // Method to handle chest collection

private:
    bool collected;
    Player* player;
    MazeView* mazeView;

};

#endif // CHEST_H
