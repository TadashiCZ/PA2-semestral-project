//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_GAME_H
#define SEMESTRAL_PROJECT_GAME_H

#include <iostream>
#include "Quiz.hpp"

unsigned long showQuizListPrompt(const unsigned long size);

/**
 * Controls the game play of given quizzes
 */
class Game {
public:
	/**
	 * Prompts the user to choose from quizzes of the Game.
	 * @return
	 */
	int showQuizList();

	/**
	 * Starts game
	 */
	void play();


};

#endif //SEMESTRAL_PROJECT_GAME_H
