#include <gtest/gtest.h>
#include "Question.h" // Include the header of the class you're testing

// Test cases for the Question struct
TEST(QuestionTest, CorrectAnswer) {
    Question q;
    q.correct_answer = "Paris";
    ASSERT_EQ(q.correct_answer, "Paris");
}

// Add more tests as needed

// Main function
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
