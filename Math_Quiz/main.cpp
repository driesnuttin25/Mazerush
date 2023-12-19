#include "QuizGame.h"
#include "Player.h"

int main() {
    MathQuiz::Player player("Dries"); // Creating a Player
    MathQuiz::QuizGame game(player); // Start a game with this player
    game.start();
    return 0;
}
