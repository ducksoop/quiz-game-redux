# 🎮 Quiz Game Redux

## Introduction 🌟
Quiz Game Redux is a modern rewrite of a classic quiz game project, originally developed as an introduction to C++ programming. This version incorporates contemporary C++ standards and features, making it an excellent example of modern C++ practices and data-oriented design.

## Features 🚀
- **Dynamic Question Pool**: Loads questions from a JSON file, allowing for easy updates and modifications to the quiz content.
- **Randomized Order**: Both questions and their corresponding choices are shuffled, ensuring a unique quiz experience each time.
- **Console-Based Interface**: Simple and intuitive text-based interface for easy navigation and interaction.

## Requirements 📋
- C++ Compiler (C++20 Standard)
- CMake for build automation
- Git (for cloning the repository and managing submodules)

## Setup and Installation 🛠️
1. **Clone the Repository**
   ```bash
   git clone https://github.com/ducksoop/quiz-game-redux.git --recurse-submodules
   cd quiz-game-redux
   ```

2. **Build the Project**
   ```bash
   cmake -B build
   cmake --build build
   ```
   This process is the same for both Windows and Linux systems.

3. **Run the Executable**
   - On Windows: `.\build\quiz-game-redux.exe`
   - On Linux: `./build/quiz-game-redux`

## Usage 🎲
- Launch the game executable to start the quiz.
- Answer the shuffled multiple-choice questions presented in the console.
- Enjoy testing your knowledge and challenging yourself!

## Cross-Platform Compatibility 🌍
- This project is designed to be built and run on both Windows and Linux operating systems.

## Contributing 🤝
Contributions to the Quiz Game Redux project are welcome! If you have suggestions for improvements or new features, feel free to fork the repo and submit a pull request.

## License ⚖️
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
