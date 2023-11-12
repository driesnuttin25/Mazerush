#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <optional>

class Maze {
public:
    Maze(int width, int height);

    void generateMaze();
    void displayMaze();

private:
    struct Cell {
        bool visited = false;
        bool top = true, bottom = true, left = true, right = true;
    };

    int m_width, m_height;
    std::vector<std::vector<Cell>> m_cells;
    std::stack<std::pair<int, int>> m_path;  // To hold the current path

    std::optional<std::pair<int, int>> chooseNextCell(int x, int y);
};

#endif
