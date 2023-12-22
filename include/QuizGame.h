#pragma once

#include "Question.h"

#include <vector>

void shuffle_questions(std::vector<Question>& questions);
void run_quiz(const std::vector<Question>& questions);