cmake_minimum_required(VERSION 3.10)
project(semestral_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wno-long-long -O0 -ggdb")

add_executable(semestral_project src/main.cpp src/UI/MainMenuScreen.hpp src/Game/Quiz.hpp src/Game/Game.hpp src/Game/Page.hpp src/Game/Question/Question.hpp src/Game/Question/TrueFalseQuestion.hpp src/Game/Question/TextQuestion.hpp src/Game/Question/TextQuestion.cpp src/Game/Question/MultiChoiceQuestion.hpp src/Database/DataHandler.hpp src/Database/DataHandler.cpp src/Database/Importer.cpp src/Database/Importer.hpp src/Constants.hpp src/Game/Game.cpp src/UI/MainMenuScreen.cpp src/Game/Question/MultiChoiceQuestion.cpp src/Game/Question/Question.cpp src/Game/Question/TrueFalseQuestion.cpp src/Game/Page.cpp src/Database/Exporter.cpp src/Database/Exporter.hpp src/Game/Quiz.cpp src/UI/Screen.cpp src/UI/Screen.hpp src/UI/GameScreen.cpp src/UI/GameScreen.hpp src/UI/ExitScreen.cpp src/UI/ExitScreen.hpp src/UI/EditorScreen.cpp src/UI/EditorScreen.hpp src/UI/AdderScreen.cpp src/UI/AdderScreen.hpp)