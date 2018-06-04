/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#ifndef SEMESTRAL_PROJECT_GAMESCREEN_HPP
#define SEMESTRAL_PROJECT_GAMESCREEN_HPP


#include "Screen.hpp"

class GameScreen : public Screen {
public:
	GameScreen(std::ostream & os);
	virtual ~GameScreen()=default;
	virtual void run() override;
	virtual void show() override;
	virtual void interact() override;

protected:
	/**
	 * Prompts the user to choose from quizzes of the Game.
	 * @param ostream to put the input in
	 * @return
	 */
	void showQuizList();

	void showQuizListPrompt(const unsigned long size);

	std::ostream & mOs;
};


#endif //SEMESTRAL_PROJECT_GAMESCREEN_HPP
