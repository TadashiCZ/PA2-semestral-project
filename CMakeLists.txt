cmake_minimum_required(VERSION 3.10)
project(semestral_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(semestral_project src/main.cpp src/UI/Menu.h src/Game/Quiz.h src/Game.h src/Game/Page.h src/Game/Question/Question.h)