#include <gtest/gtest.h>

#include "QuestionLoader.h"

TEST(QuestionLoaderTest, LoadQuestions) 
{
    auto questions = load_questions("questions.json");

    // Test whether the questions are loaded correctly
    EXPECT_GT(questions.size(), 0); // Expect at least one question loaded

    // Further checks can include validating the contents of the questions
}

TEST(QuestionLoaderTest, CorrectlyLoadsData) 
{
    auto questions = load_questions("questions.json"); // Ensure this file exists with known content

    EXPECT_GT(questions.size(), 0); // Expect that some questions are loaded

    // Optionally, check the contents of the first question if you know what it should be
    EXPECT_EQ(questions[0].id, 1); // Example, adjust according to your actual data
    EXPECT_EQ(questions[0].question, "What is the capital of France?");
    // ... similarly for choices and correct_answer
}
