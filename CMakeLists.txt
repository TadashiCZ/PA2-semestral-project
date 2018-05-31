cmake_minimum_required(VERSION 3.10)
project(semestral_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wno-long-long -O0 -ggdb")

add_executable(semestral_project src/main.cpp src/UI/Menu.hpp src/Game/Quiz.hpp src/Game.hpp src/Game/Page.hpp src/Game/Question/Question.hpp src/Game/Question/TrueFalseQuestion.hpp src/Game/Question/TextQuestion.hpp src/Game/Question/TextQuestion.cpp src/Game/Question/MultiChoiceQuestion.hpp src/IO/ExpoImpo.hpp src/IO/ExpoImpo.cpp  src/IO/Importer.cpp src/IO/Importer.hpp src/Constants.hpp)