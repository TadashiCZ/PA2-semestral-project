//
// Created by Tadeáš Valenta on 4.6.18.
//
#ifndef SEMESTRAL_PROJECT_GAMESCREEN_HPP
#define SEMESTRAL_PROJECT_GAMESCREEN_HPP


#include "Screen.hpp"

/**
 * Screen interacting with the user around game play (choosing quiz and playing it)
 */
class GameScreen : public Screen {
public:
	/**
	 * Creates screen, output will be streamed into given stream
	 * @param os
	 */
	GameScreen(std::ostream & os);
	virtual ~GameScreen() = default;
	virtual void run() override;

	/**
	 * Prompts the user to choose from quizzes of the Game.
	 * @param ostream to put the input in
	 * @return
	 */
	void showQuizList();
	void showQuizListPrompt(const unsigned long size);
private:
	virtual void show() override;
	virtual void interact() override;

	std::ostream & mOs;
};


#endif //SEMESTRAL_PROJECT_GAMESCREEN_HPP
