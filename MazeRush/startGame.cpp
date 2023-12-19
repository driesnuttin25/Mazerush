#include "startGame.h"
#include <QDebug>

// Function to start a new game level
void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player) {
    qDebug() << "Starting new game level:" << currentLevel;

    // Clean up and delete existing instances if they exist
    if (view) {
        view->scene()->clear(); // Clear the scene
        delete view; // Delete the MazeView
        view = nullptr; // Nullify the pointer
    }

    if (maze) {
        delete maze; // Delete the Maze
        maze = nullptr; // Nullify the pointer
    }

    if (player) {
        delete player; // Delete the Player
        player = nullptr; // Nullify the pointer
    }

    // Create new instances for Maze, Player, and MazeView
    maze = new Maze(mazeWidth, mazeHeight); // Create a new Maze
    player = new Player(); // Create a new Player
    view = new MazeView(maze, player, cellSize); // Create a new MazeView

    // Setup the MazeView
    view->setMaze(maze); // Set the maze in the view
    view->drawMaze(); // Draw the maze
    view->scene()->addItem(player); // Add the player to the scene
    player->setPos(cellSize, cellSize); // Set the initial position of the player
    view->show(); // Show the MazeView

    // Connect the levelCompleted signal from Player to the slot for starting a new level
    QObject::disconnect(player, &Player::levelCompleted, nullptr, nullptr); // Disconnect any existing connections
    QObject::connect(player, &Player::levelCompleted, [cellSize, &currentLevel, &view, &maze, &player]() mutable {
        currentLevel++; // Increment the level
        int newWidth = 7 + 2 * (currentLevel - 1); // Calculate new dimensions for the maze
        int newHeight = newWidth;
        startGame(newWidth, newHeight, cellSize, currentLevel, view, maze, player); // Start the new level
    });
}
