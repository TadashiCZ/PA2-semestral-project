//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_MENU_H
#define SEMESTRAL_PROJECT_MENU_H

#include <iostream>
#include "Screen.hpp"
#include "../Game/Quiz.hpp"
#include "../Database/DataHandler.hpp"

class MainMenuScreen : public Screen {
public:
	MainMenuScreen(std::ostream & os);

	virtual ~MainMenuScreen()=default;

	void welcomeUser();

	virtual void run();

	virtual void show();

	virtual void interact();

	int promptMainMenu();

	bool promptContinue();

	void goodbye();

private:
	std::ostream & mOs;
};


#endif //SEMESTRAL_PROJECT_MENU_H
