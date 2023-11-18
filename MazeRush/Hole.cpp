// Hole.cpp
#include "Hole.h"
#include <QPixmap>
#include <QApplication>

Hole::Hole(int x, int y, int cellSize) {
    QPixmap originalPixmap(":/assets/hole.png");
    QPixmap scaledPixmap = originalPixmap.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);

    qreal offsetX = cellSize * 0.2;
    qreal offsetY = cellSize * 0.2;
    setPos(x * cellSize + offsetX, y * cellSize + offsetY);
}

void Hole::interact(Player* player) {
    QApplication::quit(); // For now just ends application, I don't know man I don't have that game logic installed yet
}
