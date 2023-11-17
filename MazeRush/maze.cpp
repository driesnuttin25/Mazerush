// Maze.cpp
#include "Maze.h"
#include <random>
#include <ctime>
#include <stack>

Maze::Maze(int width, int height) : width(width), height(height), maze(height, std::vector<int>(width, 1)) {
    generateMaze();
}

const std::vector<std::vector<int>>& Maze::getLayout() const {
    return maze;
}

void Maze::generateMaze() {
    carveMazePath(1, 1); // Start from (1, 1)
}

void Maze::carveMazePath(int x, int y) {
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    maze[y][x] = 0;

    qDebug() << "Starting maze generation at:" << x << y;

    while (!stack.empty()) {
        auto [cx, cy] = stack.top();
        stack.pop();
        qDebug() << "Visiting cell:" << cx << cy;

        if (maze[cy][cx] == 0) { // Cell is part of the path
            std::vector<std::pair<int, int>> neighbours;

            // Check potential neighbors, two cells away
            if (cx - 2 > 0 && maze[cy][cx - 2] == 1) neighbours.push_back({cx - 2, cy});
            if (cy - 2 > 0 && maze[cy - 2][cx] == 1) neighbours.push_back({cx, cy - 2});
            if (cx + 2 < maze[0].size() && maze[cy][cx + 2] == 1) neighbours.push_back({cx + 2, cy});
            if (cy + 2 < maze.size() && maze[cy + 2][cx] == 1) neighbours.push_back({cx, cy + 2});

            if (!neighbours.empty()) {
                stack.push({cx, cy}); // Re-push the current cell for backtracking
                auto [nx, ny] = neighbours[gen() % neighbours.size()];
                qDebug() << "Moving to neighbor:" << nx << ny;

                // Remove the wall between the current cell and the chosen neighbor
                maze[(cy + ny) / 2][(cx + nx) / 2] = 0;
                maze[ny][nx] = 0; // Mark the new cell as part of the path

                stack.push({nx, ny});
            }
        }
    }

    qDebug() << "Maze generation completed.";
}
