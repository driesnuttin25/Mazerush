// Maze.cpp
#include "Maze.h"
#include "Hole.h"
#include <QDebug>
#include <random>
#include <ctime>
#include <stack>

Maze::Maze(int width, int height, QObject* parent)
    : QObject(parent), width(width), height(height), maze(height, std::vector<int>(width, 1)) {
    generateMaze();
    placeChests(5);
    placeHoles(5);
}

const std::vector<std::vector<int>>& Maze::getLayout() const {
    return maze;
}

void Maze::generateMaze() {
    carveMazePath(1, 1);
}

void Maze::carveMazePath(int x, int y) {
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    maze[y][x] = 0;

    while (!stack.empty()) {
        auto [cx, cy] = stack.top();
        stack.pop();

        if (maze[cy][cx] == 0) {
            std::vector<std::pair<int, int>> neighbours;

            // Check potential neighbors
            if (cx - 2 > 0 && maze[cy][cx - 2] == 1) neighbours.push_back({cx - 2, cy});
            if (cy - 2 > 0 && maze[cy - 2][cx] == 1) neighbours.push_back({cx, cy - 2});
            if (cx + 2 < width && maze[cy][cx + 2] == 1) neighbours.push_back({cx + 2, cy});
            if (cy + 2 < height && maze[cy + 2][cx] == 1) neighbours.push_back({cx, cy + 2});

            if (!neighbours.empty()) {
                stack.push({cx, cy});
                auto [nx, ny] = neighbours[gen() % neighbours.size()];
                maze[(cy + ny) / 2][(cx + nx) / 2] = 0;
                maze[ny][nx] = 0;
                stack.push({nx, ny});
            }
        }
    }
}

void Maze::placeHoles(int numberOfHoles) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distX(0, width - 1);
    std::uniform_int_distribution<int> distY(0, height - 1);

    int placedHoles = 0;
    while (placedHoles < numberOfHoles) {
        int x = distX(rng);
        int y = distY(rng);

        // Ensure the hole is not placed on a chest or at (1,1)
        if (maze[y][x] == 0 && !(x == 1 && y == 1)) {
            maze[y][x] = 3; // 3 represents a hole
            placedHoles++;
        }
    }
}


void Maze::placeChests(int numberOfChests) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distX(1, width - 2);
    std::uniform_int_distribution<int> distY(1, height - 2);

    int placedChests = 0;
    while (placedChests < numberOfChests) {
        int x = distX(rng);
        int y = distY(rng);

        if (maze[y][x] == 0) {
            maze[y][x] = 2;
            placedChests++;
        }
    }
}
