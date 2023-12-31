#include "Maze.h"
#include "Hole.h"
#include "GameConfig.h"
#include <QDebug>
#include <random>
#include <ctime>
#include <stack>

// Maze constructor
Maze::Maze(int width, int height, QObject* parent)
    : QObject(parent), width(width), height(height), maze(height, std::vector<int>(width, 1)) {
    qDebug() << "Maze Constructor called";
    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Invalid maze dimensions"); // Check for valid dimensions
    }
    generateMaze(); // Generate the maze layout
    GameConfig config("C:/Users/dries/OneDrive/Music/Documents/TcXaeShell/Tc2_DMX_Sample_DMX_Master/Desktop/Cpp/MazeRush/config.ini"); // Load game configuration
    placeChests(config.get("chests")); // Place chests
    placeHoles(config.get("holes")); // Place holes
}

// Returns the current layout of the maze
const std::vector<std::vector<int>>& Maze::getLayout() const {
    return maze;
}

// Resets and regenerates the maze with new dimensions
void Maze::reset(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    maze = std::vector<std::vector<int>>(height, std::vector<int>(width, 1));
    generateMaze();
    placeChests(5);
    placeHoles(0);
}

// Generates the maze layout using a recursive algorithm
void Maze::generateMaze() {
    qDebug() << "Generating maze";
    carveMazePath(1, 1); // Start carving the path
}

// Carves a path in the maze using a depth-first search algorithm
void Maze::carveMazePath(int x, int y) {
    qDebug() << "Carving maze path";
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    maze[y][x] = 0; // Mark the starting cell

    // Carving process
    while (!stack.empty()) {
        auto [cx, cy] = stack.top();
        stack.pop();

        // Find unvisited neighbors
        if (maze[cy][cx] == 0) {
            std::vector<std::pair<int, int>> neighbours;

            // Check potential neighbors
            if (cx - 2 > 0 && maze[cy][cx - 2] == 1) neighbours.push_back({cx - 2, cy});
            if (cy - 2 > 0 && maze[cy - 2][cx] == 1) neighbours.push_back({cx, cy - 2});
            if (cx + 2 < width && maze[cy][cx + 2] == 1) neighbours.push_back({cx + 2, cy});
            if (cy + 2 < height && maze[cy + 2][cx] == 1) neighbours.push_back({cx, cy + 2});

            // If there are neighbors, continue carving
            if (!neighbours.empty()) {
                stack.push({cx, cy});
                auto [nx, ny] = neighbours[gen() % neighbours.size()];
                maze[(cy + ny) / 2][(cx + nx) / 2] = 0; // Remove wall
                maze[ny][nx] = 0; // Mark new cell as part of the path
                stack.push({nx, ny});
            }
        }
    }
    qDebug() << "done carving maze path";
}
// Places holes in the maze
void Maze::placeHoles(int numberOfHoles) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distX(0, width - 1);
    std::uniform_int_distribution<int> distY(0, height - 1);

    int placedHoles = 0;
    // Hole placement logic
    while (placedHoles < numberOfHoles) {
        int x = distX(rng);
        int y = distY(rng);

        // Place hole if it's a valid location
        if (maze[y][x] == 0 && !(x == 1 && y == 1)) {
            maze[y][x] = 3; // 3 represents a hole
            placedHoles++;
        }
    }
}

// Places chests in the maze
void Maze::placeChests(int numberOfChests) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distX(1, width - 2);
    std::uniform_int_distribution<int> distY(1, height - 2);

    int placedChests = 0;
    // Chest placement logic
    while (placedChests < numberOfChests) {
        int x = distX(rng);
        int y = distY(rng);

        // Place chest if it's a valid location
        if (maze[y][x] == 0) {
            maze[y][x] = 2; // 2 represents a chest
            placedChests++;
        }
    }
}
