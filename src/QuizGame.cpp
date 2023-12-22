#include "QuizGame.h"
#include "QuestionLoader.h"

#include <algorithm>
#include <random>
#include <iostream>
#include <string>
#include <map>

/**
 * Shuffles the order of questions and the order of choices within each question.
 * @param questions A vector of Question structs.
 */
void shuffle_questions(std::vector<Question>& questions)
{
    std::random_device rd;  // Non-deterministic random number generator
    std::mt19937 g(rd());   // Seed with rd

    // Shuffle the questions
    std::shuffle(questions.begin(), questions.end(), g);

    // Shuffle choices within each question
    for (auto& question : questions) {
        std::shuffle(question.choices.begin(), question.choices.end(), g);
    }
}

/**
 * Runs the quiz game by iterating over a vector of questions.
 * Each question is displayed with its choices, and the user's input is taken and evaluated.
 * The user's score is calculated based on correct answers.
 *
 * @param questions A const reference to a vector of Question structs, containing the quiz questions and answers.
 */
void run_quiz(const std::vector<Question>& questions) {
    int score = 0; // Variable to keep track of the user's score
    std::string user_input; // Variable to store user's input
    char choice_label; // Variable to label choices (A, B, C, etc.)

    // Iterate over each question
    for (const auto& question : questions) {
        std::cout << question.question << "\n"; // Display the question

        // Create a map to associate choice labels with choice strings
        std::map<char, std::string> choices_map;
        choice_label = 'A';
        for (const auto& choice : question.choices) {
            std::cout << choice_label << ") " << choice << "\n"; // Display each choice
            choices_map[choice_label] = choice; // Map the label to the choice
            choice_label++;
        }

        // Get user's answer
        std::cout << "Your answer: ";
        std::cin >> user_input;

        // Convert user input to uppercase and extract the first character
        char user_choice = toupper(user_input[0]);
        // Check if the user's choice is valid and correct
        if (choices_map.find(user_choice) != choices_map.end() && choices_map[user_choice] == question.correct_answer) {
            std::cout << "Correct!\n"; // Correct answer
            score++; // Increment score
        }
        else {
            std::cout << "Wrong! Correct answer: " << question.correct_answer << "\n"; // Incorrect answer
        }

        std::cout << "\n"; // New line for spacing
    }

    // Display the user's total score after completing the quiz
    std::cout << "Quiz completed! Your score: " << score << "/" << questions.size() << "\n";
}