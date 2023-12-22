#pragma once

#include <string>
#include <vector>

struct Question {
    int id;
    std::string question;
    std::vector<std::string> choices;
    std::string correct_answer;
};