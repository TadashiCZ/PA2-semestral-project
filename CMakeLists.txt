cmake_minimum_required(VERSION 3.10)
project(semestral_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wno-long-long -O0 -ggdb")

add_executable(semestral_project src/main.cpp src/UI/Menu.h src/Game/Quiz.h src/Game.h src/Game/Page.h src/Game/Question/Question.h src/Game/Question/TrueFalseQuestion.h src/Game/Question/TextQuestion.h src/Game/Question/MultiChoiceQuestion.cpp src/Game/Question/MultiChoiceQuestion.h)