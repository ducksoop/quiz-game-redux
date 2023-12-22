#include "QuestionLoader.h"

#include <nlohmann/json.hpp>
#include <fstream>

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