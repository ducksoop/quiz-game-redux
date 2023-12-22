# CMakeList.txt : CMake project for quiz-game-redux, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (quiz-game-redux "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET quiz-game-redux PROPERTY CXX_STANDARD 20)
endif()

# Link nlohmann_json::nlohmann_json
target_link_libraries(quiz-game-redux PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add tests and install targets if needed.
