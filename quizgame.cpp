#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    int correctAnswer; // Index of the correct answer (0-based)
};

void displayQuestion(const Question& q, int questionNumber) {
    cout << "\nQuestion " << questionNumber << ": " << q.questionText << endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
    cout << "Your answer: ";
}

int main() {
    vector<Question> quiz = {
        {"Which is our national bird?", {"Parrot", "Dove", "Peacock", "Swan"}, 2},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
        {"Name the biggest continent in the world?", {"Europe", "Asia", "Antartica", "Africa"}, 1},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 1},
        {"Which element has the chemical symbol 'O'?", {"Oxygen", "Gold", "Silver", "Osmium"}, 0}
    };

    int score = 0;

    cout << "Welcome to the Quiz Game!\n";
    cout << "Answer the following questions by typing the number corresponding to your choice.\n";

    for (size_t i = 0; i < quiz.size(); ++i) {
        displayQuestion(quiz[i], i + 1);

        int userAnswer;
        cin >> userAnswer;

        if (userAnswer - 1 == quiz[i].correctAnswer) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong. The correct answer was: " << quiz[i].options[quiz[i].correctAnswer] << "\n";
        }
    }

    cout << "\nYou completed the quiz!\n";
    cout << "Your final score is: " << score << " out of " << quiz.size() << "\n";

    if (score == quiz.size()) {
        cout << "Excellent! You got all the answers right!\n";
    } else if (score >= quiz.size() / 2) {
        cout << "Good job! You answered more than half of the questions correctly.\n";
    } else {
        cout << "Better luck next time! Keep practicing.\n";
    }

    return 0;
}
