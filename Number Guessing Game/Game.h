#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <limits>
#include <random>
#include <utility>
#include <string>
#include <nlohmann/json.hpp>
#include "Utils.h"

class Game {
public:
    Game();
    void runGame();
private:
    void startMenu();
    void startSettings();
    void startGameRound();


    bool isGameRound;
    bool isSettings;
    bool isDifSettings;
    bool isRangeSettings;
    bool isExit;
    bool isMenu;
    short difficulty;
    short attemptsNumber;
    double spentTime;
    std::pair<int, int> rangeOfGuessing;
    short option = NULL;
    long choice = NULL;
    std::string username;
};

