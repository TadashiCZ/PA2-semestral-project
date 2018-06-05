//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_GAME_H
#define SEMESTRAL_PROJECT_GAME_H

#include <iostream>
#include "Quiz.hpp"

/**
 * Controls the game play of given quiz
 */
class Game {
public:
	/**
	 * Constructor which also stars the game
	 * @param quiz
	 */
	Game(Quiz & quiz);

	/**
	 * Starts game
	 */
	void play(std::ostream & os);

protected:
	/**
	 * Quiz that shall be played
	 */
	Quiz mQuiz;

};

#endif //SEMESTRAL_PROJECT_GAME_H
