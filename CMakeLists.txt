cmake_minimum_required(VERSION 3.10)
project(NumberGuessingGame)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/nlohmann_json)

add_executable(number_guessing_game "number guessing game/main.cpp" "number guessing game/Game.cpp" "number guessing game/Utils.cpp")

target_link_libraries(number_guessing_game PRIVATE nlohmann_json::nlohmann_json)
