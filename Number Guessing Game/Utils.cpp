#include "Utils.h"

void Utils::saveJsonToFile(const json& j, const std::string username) {
    std::string path = "saves/" + username + ".json";
    std::ofstream file(path);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    }
    else {
        throw std::runtime_error("Unable to save file: " + path);
    }
}

json Utils::loadJsonFromFile(const std::string& username) {
    std::string path = "saves/" + username + ".json";
    std::ifstream file(path);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();
        return j;
    }
    else {
        throw std::runtime_error("Unable to load file: " + path);
    }
}

std::string Utils::getDate() {
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << now.tm_mday << "."
        << std::setfill('0') << std::setw(2) << now.tm_mon + 1 << "."
        << now.tm_year + 1900;
    return oss.str();
}

long Utils::createRandomNumber(const std::pair<int, int> rangeOfGuessing) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(rangeOfGuessing.first, rangeOfGuessing.second);
    return dis(gen);
}

short Utils::getValidInput(const short minValue, const short maxValue) {
    short input;
    while (1) {
        std::cin >> input;
        if (std::cin.fail() || input < minValue || input > maxValue) {
            std::cerr << "\nIncorrect input. Please enter a number between " << minValue << " and " << maxValue << ".\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return input;
}

void Utils::saveStats(const std::string username, short difficulty, short attemptsNumber, double spentTime) {
    json j;
    j["possible_attempts"] = "" + std::to_string(difficulty);
    j["attempts_spent"] = "" + std::to_string(attemptsNumber);
    j["username"] = "" + username;
    j["date"] = "" + getDate();
    j["time_spent"] = "" + std::to_string(spentTime);
    saveJsonToFile(j, username);
}
