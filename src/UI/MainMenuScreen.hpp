//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_MENU_H
#define SEMESTRAL_PROJECT_MENU_H

#include <iostream>
#include "Screen.hpp"
#include "../Game/Quiz.hpp"
#include "../Database/DataHandler.hpp"

/**
 * Screen to hold main menu which user will see first in the app
 */
class MainMenuScreen : public Screen {
public:
	/**
	 * Creates screen, output will be streamed into given stream
	 * @param os
	 */
	MainMenuScreen(std::ostream & os);

	virtual ~MainMenuScreen()=default;

	virtual void run();

private:
	void welcomeUser();

	virtual void show();

	virtual void interact();

	int promptMainMenu();

	bool promptContinue();

private:
	std::ostream & mOs;
};


#endif //SEMESTRAL_PROJECT_MENU_H
