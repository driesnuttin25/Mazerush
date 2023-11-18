// main.cpp
#include <QApplication>
#include "Maze.h"
#include "MazeView.h"
#include "Player.h" // Include the Player header
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int mazeWidth = 19; // Width of the maze in cells
    int mazeHeight = 19; // Height of the maze in cells
    int cellSize = 50; // Size of each cell in pixels

    qDebug() << "Creating maze with dimensions:" << mazeWidth << mazeHeight;

    Maze maze(mazeWidth, mazeHeight); // Maze object
    Player* player = new Player();
    player->setRect(0, 0, 20, 20); // Set player size
    player->setBrush(QBrush(Qt::blue)); // Set player color
    player->setFlag(QGraphicsItem::ItemIsFocusable); // Make the player focusable
    player->setFocus(); // Set focus to the player

    MazeView view(&maze, player, cellSize);
    view.scene()->addItem(player);
    player->setPos(cellSize, cellSize);

    qDebug() << "Showing view.";
    view.show();

    qDebug() << "Starting application.";
    return app.exec();
}
