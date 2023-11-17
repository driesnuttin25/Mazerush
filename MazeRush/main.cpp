#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <vector>
#include <random>
#include <ctime>
#include <stack>

void carveMazePath(std::vector<std::vector<int>>& maze, int x, int y) {
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr))); // Random number generator
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    maze[y][x] = 0; // Mark the starting cell as part of the path

    while (!stack.empty()) {
        auto [cx, cy] = stack.top();
        std::vector<std::pair<int, int>> neighbours;

        // Check potential neighbors, two cells away
        if (cx - 2 > 0 && maze[cy][cx - 2] == 1) neighbours.push_back({cx - 2, cy});
        if (cy - 2 > 0 && maze[cy - 2][cx] == 1) neighbours.push_back({cx, cy - 2});
        if (cx + 2 < maze[0].size() && maze[cy][cx + 2] == 1) neighbours.push_back({cx + 2, cy});
        if (cy + 2 < maze.size() && maze[cy + 2][cx] == 1) neighbours.push_back({cx, cy + 2});

        if (!neighbours.empty()) {
            auto [nx, ny] = neighbours[gen() % neighbours.size()]; // Choose a random neighbor

            // Remove the wall between the current cell and the chosen neighbor
            maze[(cy + ny) / 2][(cx + nx) / 2] = 0;

            stack.push({nx, ny});
            maze[ny][nx] = 0; // Mark the neighbor as part of the path
        } else {
            stack.pop(); // Backtrack if no unvisited neighbors are available
        }
    }
}

std::vector<std::vector<int>> generateMaze(int width, int height) {
    std::vector<std::vector<int>> maze(height, std::vector<int>(width, 1));
    carveMazePath(maze, 1, 1); // Start from (1, 1)
    return maze;
}


// Function to draw the maze
void drawMaze(QGraphicsScene* scene, int cellSize, const std::vector<std::vector<int>>& maze) {
    for (size_t y = 0; y < maze.size(); ++y) {
        for (size_t x = 0; x < maze[y].size(); ++x) {
            if (maze[y][x] == 1) { // Draw walls
                QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, cellSize, cellSize);
                rect->setPos(x * cellSize, y * cellSize);
                QBrush brush(Qt::gray); // Wall color
                rect->setBrush(brush);
                scene->addItem(rect);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QGraphicsView view;
    QGraphicsScene scene;
    view.setScene(&scene);

    int cellSize = 20;
    int mazeWidth = 29;
    int mazeHeight = 29;

    std::vector<std::vector<int>> mazeLayout = generateMaze(mazeWidth, mazeHeight);
    drawMaze(&scene, cellSize, mazeLayout);

    view.setSceneRect(0, 0, mazeWidth * cellSize, mazeHeight * cellSize);
    view.show();

    return app.exec();
}
