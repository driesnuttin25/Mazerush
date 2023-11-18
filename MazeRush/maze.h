// Maze.h
#ifndef MAZE_H
#define MAZE_H

#include "qgraphicsitem.h"
#include <QObject>
#include <vector>

class Maze : public QObject {
    Q_OBJECT

public:
    Maze(int width, int height, QObject* parent = nullptr);
    const std::vector<std::vector<int>>& getLayout() const;
    void updateTile(int x, int y);
    int width, height;
    void placeChests(int numberOfChests);
    void placeHoles(int numberOfHoles);


private:
    std::vector<std::vector<int>> maze;
    QGraphicsTextItem* coinDisplay;

    void generateMaze();
    void carveMazePath(int x, int y);
};

#endif // MAZE_H
