#include "Maze.h"
#include <iostream>
#include <random>

Maze::Maze(int width, int height) : m_width(width), m_height(height) {
    m_cells = std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));
    srand(time(nullptr));  // Seed for random number generation
}

void Maze::generateMaze() {
    int startX = rand() % m_width;
    int startY = rand() % m_height;
    m_cells[startX][startY].visited = true;
    m_path.push({startX, startY});

    while (!m_path.empty()) {
        auto [x, y] = m_path.top();
        auto next = chooseNextCell(x, y);

        if (next) {
            int nextX = next->first, nextY = next->second;

            // Remove walls between current cell and next cell
            if (x > nextX) { // Move left
                m_cells[x][y].left = false;
                m_cells[nextX][nextY].right = false;
            } else if (x < nextX) { // Move right
                m_cells[x][y].right = false;
                m_cells[nextX][nextY].left = false;
            }

            std::cout << "Moving from (" << x << ", " << y << ") to (" << nextX << ", " << nextY << ")\n";

            m_cells[nextX][nextY].visited = true;
            m_path.push({nextX, nextY});
        } else {
            m_path.pop();
            std::cout << "Backtracking from (" << x << ", " << y << ")\n";
        }
    }
}

void Maze::displayMaze() {
    // Print the top boundary
    for (int x = 0; x < 2 * m_width + 1; ++x) {
        std::cout << (x % 2 == 0 ? '+' : '-');
    }
    std::cout << std::endl;

    for (int y = 0; y < m_height; ++y) {
        // Print the left boundary
        std::cout << '|';
        for (int x = 0; x < m_width; ++x) {
            // Print the cell's space
            std::cout << (m_cells[x][y].visited ? ' ' : '#');

            // Print the wall to the right if it exists
            std::cout << (m_cells[x][y].right ? '|' : ' ');
        }
        std::cout << std::endl;

        // Print the horizontal walls below the current row of cells
        std::cout << '254';
        for (int x = 0; x < m_width; ++x) {
            std::cout << (m_cells[x][y].bottom ? '-' : ' ');
            std::cout << '+';
        }
        std::cout << std::endl;
    }
}



std::optional<std::pair<int, int>> Maze::chooseNextCell(int x, int y) {
    std::vector<std::pair<int, int>> neighbors;

    // Check each neighbor (up, down, left, right)
    if (x > 0 && !m_cells[x - 1][y].visited) {
        neighbors.push_back({x - 1, y});
    }
    if (y > 0 && !m_cells[x][y - 1].visited) {
        neighbors.push_back({x, y - 1});
    }
    if (x < m_width - 1 && !m_cells[x + 1][y].visited) {
        neighbors.push_back({x + 1, y});
    }
    if (y < m_height - 1 && !m_cells[x][y + 1].visited) {
        neighbors.push_back({x, y + 1});
    }

    // Pick a random unvisited neighbor
    if (!neighbors.empty()) {
        int randomIndex = std::rand() % neighbors.size();
        return neighbors[randomIndex];
    }

    return std::nullopt;
}
