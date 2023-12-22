#include <gtest/gtest.h>

#include "Question.h"

TEST(QuestionStructTest, StoresAndRetrievesDataCorrectly) 
{
    Question q;
    q.id = 1;
    q.question = "Sample Question";
    q.choices = { "Choice1", "Choice2", "Choice3" };
    q.correct_answer = "Choice1";

    EXPECT_EQ(q.id, 1);
    EXPECT_EQ(q.question, "Sample Question");
    EXPECT_EQ(q.choices.size(), 3);
    EXPECT_EQ(q.correct_answer, "Choice1");
}
