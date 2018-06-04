/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#include <iostream>
#include "ExitScreen.hpp"
#include "../Constants.hpp"

using namespace std;

ExitScreen::ExitScreen(std::ostream & os) : mOs( os ) {}

void ExitScreen::run() {
	show();
}

void ExitScreen::show() {
	cout << COLOR_CYAN << "Goodbye and thanks for playing." << COLOR_RESET << endl;
	cout << COLOR_CYAN << "You played game by Tadeas Valenta made for FIT CTU in 2018." << COLOR_RESET << endl;
}

void ExitScreen::interact() {

}


