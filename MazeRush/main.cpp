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
    Maze maze(mazeWidth, mazeHeight);
    MazeView view(maze, cellSize);

    Player* player = new Player();
    QSizeF playerSize = player->getPlayerSize();
    player->setRect(0, 0, playerSize.width(), playerSize.height());
    player->setBrush(QBrush(Qt::blue));
    view.scene()->addItem(player);
    player->setPos(cellSize, cellSize);

    // Make the player focusable and set the focus to receive key events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    qDebug() << "Showing view.";
    view.show();

    qDebug() << "Player size:" << player->rect().size();
    qDebug() << "Player position:" << player->pos();


    qDebug() << "Starting application.";
    return app.exec();
}
