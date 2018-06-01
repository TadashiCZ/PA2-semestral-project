//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_GAME_H
#define SEMESTRAL_PROJECT_GAME_H

#include <iostream>
#include "Game/Quiz.hpp"

unsigned long showQuizListPrompt(const unsigned long size);

class Game {
public:
	Game(std::vector<Quiz> & quizzes);

	int showQuizList();

	void play();


protected:
	std::vector<Quiz> & mQuizzes;


};

#endif //SEMESTRAL_PROJECT_GAME_H
