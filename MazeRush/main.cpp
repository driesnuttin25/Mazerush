#include <QApplication>
#include "TitleScreen.h"
#include "GameConfig.h"
#include "Maze.h"
#include "MazeView.h"
#include "Player.h"
#include "startGame.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Application started";

    // Load game configuration settings
    GameConfig config("C:/Users/dries/OneDrive/Music/Documents/TcXaeShell/Tc2_DMX_Sample_DMX_Master/Desktop/Cpp/MazeRush/config.ini");

    // Retrieve initial maze dimensions from the configuration
    int initialMazeWidth = config.get("maze_width");
    int initialMazeHeight = config.get("maze_height");
    int cellSize = 50; // Set a fixed cell size
    int currentLevel = 1; // Start from level 1

    // Initialize pointers for the maze, view, and player
    MazeView* view = nullptr;
    Maze* maze = nullptr;
    Player* player = nullptr;

    // Create and display the title screen
    TitleScreen titleScreen;
    QObject::connect(&titleScreen, &TitleScreen::startGame, [&](){
        qDebug() << "Start game signal received";
        // Start the game when the 'Start Game' button is clicked
        startGame(initialMazeWidth, initialMazeHeight, cellSize, currentLevel, view, maze, player);
        titleScreen.hide(); // Hide the title screen
    });

    titleScreen.show(); // Show the title screen
    qDebug() << "Title screen shown";
    return app.exec(); // Run the application event loop
}
