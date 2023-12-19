#pragma once
#include <string>

namespace MathQuiz {

class Question {
public:
    Question() : text("What is 2 + 2?"), answer(4) {} // Default constructor
    Question(const std::string& text, int answer) : text(text), answer(answer) {} // Parameterized constructor
    Question(const Question& other) : text(other.text), answer(other.answer) {} // Copy constructor
    ~Question() {} // Destructor

    bool checkAnswer(int response) const {
        return response == answer;
    }

    const std::string& getText() const {
        return text;
    }

private:
    std::string text;
    int answer;
};

}
