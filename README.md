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

To run the game, you need a C++ compiler. Follow these steps fot MSVC:

1. Clone the repository:
   ```sh
   git clone https://github.com/Vlademyanov/Number-Guessing-Game
2. Navigate to the project directory:
   ```sh
   cd number-guessing-game
3. Install the nlohmann/json library:

   ```sh
   git submodule add https://github.com/nlohmann/json.git external/nlohmann_json
   git submodule update --init --recursive

4. Create a build directory and navigate into it:

   ```sh
   mkdir build
   cd build

5. Run CMake to generate Visual Studio project files:
   ```sh
   cmake -G "Visual Studio 17 2022" ..
   
6. Open the generated NumberGuessingGame.sln file in Visual Studio.

7. Build the project in Visual Studio:

- Select the build configuration (e.g., Debug or Release).
- Click Build -> Build Solution (or press Ctrl+Shift+B).

8. Run the game:

- Press Local Windows Debugger (or press F5).

## Project Roadmap

This project is part of the [Number Guessing Game Roadmap](https://roadmap.sh/projects/number-guessing-game).

##Contributing

Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request.

Happy guessing!







