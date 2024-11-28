cmake_minimum_required(VERSION 3.10)
project(NumberGuessingGame)

set(CMAKE_CXX_STANDARD 17)

# Добавляем подмодуль nlohmann/json
add_subdirectory(external/nlohmann_json)

# Добавляем исполняемый файл
add_executable(number_guessing_game "number guessing game/main.cpp" "number guessing game/Game.cpp" "number guessing game/Utils.cpp")

# Связываем библиотеку nlohmann_json с нашим проектом
target_link_libraries(number_guessing_game PRIVATE nlohmann_json::nlohmann_json)
