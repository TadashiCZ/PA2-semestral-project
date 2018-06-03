//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_MENU_H
#define SEMESTRAL_PROJECT_MENU_H

#include <iostream>
#include "Screen.hpp"
#include "../Game/Quiz.hpp"
#include "../IO/DataHandler.hpp"

namespace MainMenu {

	void run( DataHandler data );

	void welcomeUser();

	void run();

	void show();

	int promptMainMenu();

	bool promptContinue();

	void goodbye();
}


#endif //SEMESTRAL_PROJECT_MENU_H
