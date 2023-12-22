# CMakeList.txt : CMake project for quiz-game-redux, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (quiz-game-redux "main.cpp"  "QuestionLoader.cpp" "QuizGame.cpp")

# Post-build command to copy questions.json to the build directory
add_custom_command(TARGET quiz-game-redux POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/data/questions.json"
    "$<TARGET_FILE_DIR:quiz-game-redux>/questions.json")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET quiz-game-redux PROPERTY CXX_STANDARD 20)
endif()

# Link nlohmann_json::nlohmann_json
target_link_libraries(quiz-game-redux PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add tests and install targets if needed.
