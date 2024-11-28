#include "Game.h"


Game::Game() :
    isSettings(true),
    isMenu(true),
    isGameRound(true),
    isDifSettings(true),
    isRangeSettings(true),
    isExit(false),
    rangeOfGuessing(1, 100),
    difficulty(5)
{}

void Game::runGame() {
    std::cout << "\nWelcome to the Number Guessing Game!";
    while (!isExit) {
        startMenu();
        isMenu = true;
    }
}

void Game::startMenu() {
    while (isMenu) {
        std::cout << "\n\n1. Start game\n2. Settings\n3. Check Stats\n4. Exit game\n\nEnter your choice: ";
        option = Utils::getValidInput(1, 4);

        switch (option) {
        case 1:
            isMenu = false;
            startGameRound();
            break;
        case 2:
            isMenu = false;
            startSettings();
            break;
        case 3:
            isMenu = false;
            std::cout << "\nYour Name is: ";
            std::cin >> username;
            try {
                json loaded_json = Utils::loadJsonFromFile(username);
                std::cout << "\nusername: " << loaded_json["username"];
                std::cout << "\npossible_attempts: " << loaded_json["possible_attempts"];
                std::cout << "\nattempts_spent: " << loaded_json["attempts_spent"];
                std::cout << "\ntime_spent: " << loaded_json["time_spent"];
                std::cout << "\ndate: " << loaded_json["date"];
            }
            catch (std::runtime_error) {
                std::cerr << "\nUnable to load file";
            }
            break;
        case 4:
            std::cout << "\nGoodbye!";
            isMenu = false;
            isExit = true;
            break;
        default:
            break;
        }
    }
}

void Game::startSettings() {
    isSettings = true;
    while (isSettings) {
        std::cout << "\nPlease select the options\n1. Difficulty level\n2. Guessing range\n3. Exit settings\n\nEnter your choice: ";
        option = Utils::getValidInput(1, 3);

        switch (option) {
        case 1:
            isDifSettings = true;
            while (isDifSettings) {
                std::cout << "\nPlease select the difficulty level:\n1. Easy (10 chances)\n2. Medium (5 chances)\n3. Hard (3 chances)\n4. Exit difficulty settings\n\nEnter your choice: ";
                option = Utils::getValidInput(1, 4);
                switch (option) {
                case 1:
                    isDifSettings = false;
                    difficulty = 10;
                    std::cout << "\nGreat! You have selected the Easy difficulty level." << std::endl;
                    break;
                case 2:
                    isDifSettings = false;
                    difficulty = 5;
                    std::cout << "\nGreat! You have selected the Medium difficulty level." << std::endl;
                    break;
                case 3:
                    isDifSettings = false;
                    difficulty = 3;
                    std::cout << "\nGreat! You have selected the Hard difficulty level." << std::endl;
                    break;
                case 4:
                    isDifSettings = false;
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            isRangeSettings = true;
            while (isRangeSettings) {
                std::cout << "\nPlease enter the minimal value: ";
                rangeOfGuessing.first = Utils::getValidInput();
                std::cout << "\nPlease enter the maximal value: ";
                rangeOfGuessing.second = Utils::getValidInput();

                if (rangeOfGuessing.first > rangeOfGuessing.second) {
                    std::cerr << "\nIncorrect input. The minimal value must be less than the maximal value.\n" << std::endl;
                }
                else {
                    std::cout << "\nGreat!\n\nThe minimal value is " << rangeOfGuessing.first << "\nThe maximal value is " << rangeOfGuessing.second << std::endl;
                    isRangeSettings = false;
                }
            }
            break;
        case 3:
            isSettings = false;
            break;
        default:
            break;
        }
    }
}

void Game::startGameRound() {
    isGameRound = true;
    while (isGameRound) {

        long randomNumber = Utils::createRandomNumber(rangeOfGuessing);
        std::string str;
        std::cout << "\nLet's start the game!\nI'm thinking of a number between " << rangeOfGuessing.first << " and " << rangeOfGuessing.second << ".\nYou have " << difficulty << " chances to guess the correct number." << std::endl;
        std::clock_t start = std::clock();
        for (short i = difficulty; i > 0; i--) {
            std::cout << "\nEnter your choice: ";
            choice = Utils::getValidInput();
            if (choice == randomNumber) {
                attemptsNumber = difficulty - i + 1;
                std::clock_t end = std::clock();
                spentTime = (end - start) / (double)CLOCKS_PER_SEC;
                std::cout << "\nCongratulations! You guessed the correct number in " << attemptsNumber << " attempts.\nYou've spent " << spentTime << " seconds!\nSave the result?\n1. no\n2. yes\nEnter your choice: ";
                option = Utils::getValidInput(1, 2);
                if (option == 2) {
                    std::cout << "Your Name is: ";
                    std::cin >> username;
                    try {
                        Utils::saveStats(username, difficulty, attemptsNumber, spentTime);
                    }
                    catch (std::runtime_error) {
                        std::cerr << "Unable to save file";
                    }
                }
                isGameRound = false;
                break;
            }
            else {
                if (choice < randomNumber) str = "greater";
                else str = "less";
                std::cout << "\nIncorrect! The number is " << str << " than " << choice << "." << std::endl;
            }
        }
        std::cout << "\nYou've lost! The number that I was thinking of was " << randomNumber << "!" << std::endl;
        isGameRound = false;
    }
}