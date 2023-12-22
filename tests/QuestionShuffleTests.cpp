#include <gtest/gtest.h>

#include "QuestionLoader.h"
#include "QuizGame.h"

TEST(QuestionShuffleTest, ShuffleQuestions) 
{
    auto questions = load_questions("questions.json");
    auto original_questions = questions; // Make a copy before shuffling

    shuffle_questions(questions);

    // Test whether the order of questions is changed
    EXPECT_NE(questions, original_questions); // This test can be flaky if shuffle results in the same order

    // Test whether each question still contains the correct answer
    for (size_t i = 0; i < questions.size(); ++i)
    {
        EXPECT_EQ(questions[i].correct_answer, original_questions[i].correct_answer);
    }
}

TEST(QuestionShuffleTest, QuestionsMaintainIntegrityAfterShuffling) {
    auto questions = load_questions("questions.json");
    auto original_questions = questions; // Make a copy before shuffling

    shuffle_questions(questions);

    for (size_t i = 0; i < questions.size(); ++i) 
    {
        // Check that the correct answer is still in the choices
        auto found = std::find(questions[i].choices.begin(), questions[i].choices.end(), questions[i].correct_answer);
        EXPECT_NE(found, questions[i].choices.end());

        // Check that all original choices are still present
        for (const auto& choice : original_questions[i].choices)
        {
            EXPECT_NE(std::find(questions[i].choices.begin(), questions[i].choices.end(), choice), questions[i].choices.end());
        }
    }
}