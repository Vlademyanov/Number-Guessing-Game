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

using json = nlohmann::json;

class Utils {
public:
    static void saveJsonToFile(const json& j, const std::string username);
    static json loadJsonFromFile(const std::string& username);
    static std::string getDate();
    static long createRandomNumber(const std::pair<int, int> rangeOfGuessing);
    static short getValidInput(const short minValue = std::numeric_limits<short>::min(), const short maxValue = std::numeric_limits<short>::max());
    static void saveStats(const std::string username, short difficulty, short attemptsNumber, double spentTime);
};

