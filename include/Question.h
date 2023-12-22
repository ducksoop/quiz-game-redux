#pragma once

#include <string>
#include <vector>

struct Question 
{
    int id;
    std::string question;
    std::vector<std::string> choices;
    std::string correct_answer;

    bool operator==(const Question& other) const 
    {
        return id == other.id && question == other.question &&
            choices == other.choices && correct_answer == other.correct_answer;
    }
};