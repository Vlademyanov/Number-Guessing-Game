# Number Guessing Game

Welcome to the Number Guessing Game! This is a simple console-based game where the player tries to guess a randomly generated number within a specified range and difficulty level.

## Features

- **Start Game**: Begin a new game round with the current settings.
- **Settings**: Adjust the difficulty level and guessing range.
- **Difficulty Levels**: Easy (10 chances), Medium (5 chances), Hard (3 chances).
- **Customizable Range**: Set your own minimum and maximum values for guessing.
- **User-Friendly Interface**: Clear instructions and feedback for the user.

## How to Play

1. **Start the Game**: Choose option 1 from the main menu to start a new game round.
2. **Guess the Number**: Enter your guess based on the hints provided.
3. **Adjust Settings**: Go to the settings menu to change the difficulty level or guessing range.

## Installation

To run the game, you need a C++ compiler. Follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/Vlademyanov/Number-Guessing-Game
2. Navigate to the project directory:
   ```sh
   cd number-guessing-game/Number Guessing Game
3. Install the nlohmann/json library:

- If you are using vcpkg (C++ package manager), you can install the library with the following command:

   ```sh
   vcpkg install nlohmann-json
   
- If you prefer to download the library manually, you can get it from the nlohmann/json GitHub repository. Place the json.hpp file in an include directory within your project.

4. Compile the code:

- If using vcpkg, ensure your build system is integrated with vcpkg. For example, with CMake:
   ```sh
   set(CMAKE_TOOLCHAIN_FILE path/to/vcpkg/scripts/buildsystems/vcpkg.cmake)
- If you downloaded the library manually, compile the code with:
   ```sh
   g++ -Iinclude main.cpp Game.cpp -o number_guessing_game
5. Compile the code:
   ```sh
   g++ -o number_guessing_game main.cpp
6. Run the game:
   ```sh
   ./number_guessing_game


## Project Roadmap

This project is part of the [Number Guessing Game Roadmap](https://roadmap.sh/projects/number-guessing-game).


##Contributing

Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request.

Happy guessing!







