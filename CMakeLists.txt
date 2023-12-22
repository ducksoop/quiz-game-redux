# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Project name
project ("quiz-game-redux")

# Enable testing functionality for Google Test
enable_testing()

# Check if the compiler is MSVC (Microsoft Visual C++)
if(MSVC)
    # Enable Hot Reload for MSVC compilers if supported.
    if (POLICY CMP0141)
        cmake_policy(SET CMP0141 NEW)
    endif()

    # Set debug information format for MSVC compilers
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")

    # Choose either dynamic or static runtime library, but not both
    # Uncomment the one you need and comment out the other
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    # set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Add Google Test as a subdirectory
add_subdirectory(extern/googletest)

# Include the Google Test headers
include_directories(extern/googletest/googletest/include)

# Create the test executable
add_executable(quiz-game-redux-tests
    
 "tests/QuestionLoaderTests.cpp" "tests/QuestionShuffleTests.cpp"  "tests/QuestionStructTests.cpp")

# Link Google Test to the test executable
target_link_libraries(quiz-game-redux-tests gtest gtest_main)

# Include directory for project header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add sub-projects (e.g., the main application code)
add_subdirectory ("src")

# Add the json library as a subdirectory
add_subdirectory(extern/json)
