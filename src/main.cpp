#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

// Define a struct to represent a question
struct Question
{
    int id;
    std::string question;
    std::vector<std::string> choices;
    std::string correct_answer;
};

/**
 * Loads questions from a JSON file.
 * @param file_path Path to the JSON file.
 * @return A vector of Question structs populated from the JSON file.
 */
std::vector<Question> load_questions(const std::string& file_path) 
{
    std::ifstream file(file_path);
    nlohmann::json json_data;
    file >> json_data;  // Load JSON data from file

    std::vector<Question> questions;
    for (const auto& item : json_data) {
        Question q;
        q.id = item["id"].get<int>();
        q.question = item["question"].get<std::string>();
        q.choices = item["choices"].get<std::vector<std::string>>();
        q.correct_answer = item["correct_answer"].get<std::string>();

        questions.push_back(q);
    }
    return questions;
}

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

int main()
{
    std::string file_path = "questions.json";  // Specify the path to your JSON file
    auto questions = load_questions(file_path);  // Load questions from file
    shuffle_questions(questions);  // Shuffle the order of questions and choices

    // Loop through each question and print it out with its choices
    for (const auto& question : questions) {
        std::cout << "Question ID: " << question.id << std::endl;
        std::cout << question.question << std::endl;

        char choice_label = 'A';
        for (const auto& choice : question.choices) {
            std::cout << choice_label << ") " << choice << std::endl;
            choice_label++;
        }

        std::cout << std::endl; // Add an extra line for spacing
    }

    return 0;
}
