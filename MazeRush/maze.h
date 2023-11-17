// Maze.h
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <QDebug>


class Maze {
public:
    Maze(int width, int height);
    const std::vector<std::vector<int>>& getLayout() const;

private:
    int width, height;
    std::vector<std::vector<int>> maze;

    void generateMaze();
    void carveMazePath(int x, int y);
};

#endif // MAZE_H
