#include "Question.h"
#include "Player.h"
#include <vector>
#include <iostream>

namespace MathQuiz {

class QuizGame {
public:
    QuizGame(Player& player) : player(player), currentQuestionIndex(0) {
        // Populate with some default questions
        questions.emplace_back("What is 3 + 5?", 8);
        questions.emplace_back("What is 10 - 7?", 3);
        questions.emplace_back("What is 15 / 3?", 5);
    }

    void start() {
        std::cout << "Welcome, " << player.getName() << "!\n";
        for (const auto& question : questions) {
            askQuestion(question);
        }
        std::cout << "Game over! Your score: " << player.getScore() << "\n";
    }

private:
    Player& player;
    std::vector<Question> questions;
    size_t currentQuestionIndex;

    void askQuestion(const Question& question) {
        std::cout << "Question: " << question.getText() << "\n";
        int response;
        std::cin >> response;
        if (question.checkAnswer(response)) {
            std::cout << "Correct!\n";
            player.incrementScore();
        } else {
            std::cout << "Wrong!\n";
        }
        currentQuestionIndex++;
    }
};

}
