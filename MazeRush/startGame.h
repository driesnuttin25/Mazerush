#ifndef STARTGAME_H
#define STARTGAME_H

#include "Maze.h"
#include "MazeView.h"
#include "Player.h"

void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player);

#endif // STARTGAME_H
