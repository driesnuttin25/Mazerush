#include "Maze.h"
#include "player.h"
#include "game.h"


int main() {
    // Set the size of the maze
    const int mazeWidth = 10;
    const int mazeHeight = 10;

    // Create the maze object
    Maze maze(mazeWidth, mazeHeight);

    // Generate the maze
    maze.generateMaze();

    // Game loop - In a console-based game, this might be a simple loop
    // where you display the maze, get the player's input, and update the game state.
    bool isGameOver = false;
    while (!isGameOver) {
        // Display the maze
        maze.displayMaze();
        std::cout << "maze has been generated";
        return 0;

        // Handle player input (if you have a player implemented)
        // Update the game state (like player's position)

        // Check for game over condition
        // isGameOver = checkGameOverCondition();

        // You can add a small delay here for better visibility if needed
    }

    // End of the game
    // You can display a game over message or the final state of the game

    return 0;
}
