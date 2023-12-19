// Maze.h
#ifndef MAZE_H
#define MAZE_H

#include "qgraphicsitem.h"
#include <QObject>
#include <vector>

// Maze class: Handles the maze structure and its dynamics
class Maze : public QObject {
    Q_OBJECT

public:
    Maze(int width, int height, QObject* parent = nullptr); // Constructor for creating the maze
    const std::vector<std::vector<int>>& getLayout() const; // Returns the layout of the maze
    void updateTile(int x, int y); // Updates a specific tile in the maze
    int width, height; // Dimensions of the maze
    void placeChests(int numberOfChests); // Places chests in the maze
    void placeHoles(int numberOfHoles); // Places holes in the maze
    void reset(int newWidth, int newHeight); // Resets and resizes the maze

private:
    std::vector<std::vector<int>> maze; // 2D vector representing the maze layout
    QGraphicsTextItem* coinDisplay; // Display for coins

    void generateMaze(); // Generates the maze layout
    void carveMazePath(int x, int y); // Carves a path in the maze
};

#endif // MAZE_H
