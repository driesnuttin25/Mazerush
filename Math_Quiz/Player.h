#pragma once
#include <string>

namespace MathQuiz {

class Player {
public:
    // Default constructor with forwarding
    Player() : Player("Guest") {}

    // Constructor with name parameter
    Player(const std::string& name) : playerName(name), playerScore(0) {}

    // Copy constructor
    Player(const Player& other)
        : playerName(other.playerName), playerScore(other.playerScore) {}

    // Destructor
    ~Player() {
    }

    void incrementScore() {
        playerScore++;
    }

    const std::string& getName() const {
        return playerName;
    }

    int getScore() const {
        return playerScore;
    }

private:
    std::string playerName;
    int playerScore;
};

}
