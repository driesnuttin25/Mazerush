#include "Hole.h"
#include <QPixmap>
#include <QApplication>

// Constructor for the Hole class
Hole::Hole(int x, int y, int cellSize) {
    // Load and scale the hole image
    QPixmap originalPixmap(":/assets/hole.png");
    QPixmap scaledPixmap = originalPixmap.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);

    // Offset for positioning the hole within the cell
    qreal offsetX = cellSize * 0.2;
    qreal offsetY = cellSize * 0.2;
    setPos(x * cellSize + offsetX, y * cellSize + offsetY);
}

// Defines interaction behavior when the player encounters a hole
void Hole::interact(Player* player) {
    QApplication::quit(); // Temporarily ends the application when the player falls into a hole
}
