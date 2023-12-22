#include "QuestionLoader.h"
#include "QuizGame.h"

int main() 
{
    std::string file_path = "questions.json";
    auto questions = load_questions(file_path);

    shuffle_questions(questions);
    run_quiz(questions);

    return 0;
}
