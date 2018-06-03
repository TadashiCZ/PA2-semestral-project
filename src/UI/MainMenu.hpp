//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_MENU_H
#define SEMESTRAL_PROJECT_MENU_H

#include <iostream>
#include <vector>

class Menu {
public:
	void showMainMenu();

	int promptMainMenu();

protected:
	std::vector<std::string> mMenuChoices;


};


#endif //SEMESTRAL_PROJECT_MENU_H
