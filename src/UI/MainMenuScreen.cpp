//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "MainMenuScreen.hpp"
#include "../Constants.hpp"
#include "../Game/Game.hpp"
#include "../Database/DataHandler.hpp"
#include "GameScreen.hpp"
#include "ExitScreen.hpp"
#include "CreatorScreen.hpp"

using namespace std;

MainMenuScreen::MainMenuScreen(ostream & os) : mOs(os){}

void MainMenuScreen::run(){

	MainMenuScreen::welcomeUser();
	bool looping = true;
	bool showMenu = false;
	MainMenuScreen::show();
	while ( looping ) {
		if ( showMenu ) MainMenuScreen::show();
		switch ( MainMenuScreen::promptMainMenu() ) {
			case 1: // Play
				if ( DataHandler::getInstance().mQuizzes.size() == 0){
					cout << "There's no quiz to be played. Please create one first." << endl;
					break;
				}
				showMenu = true;
				GameScreen(cout).run();
				if ( !promptContinue() ) {
					DataHandler::getInstance().saveQuizData();
					ExitScreen(cout).run();
					return;
				}
				break;
			case 2: // Add
				showMenu = true;
				CreatorScreen(cout).run();
				if ( !promptContinue() ) {
					DataHandler::getInstance().saveQuizData();
					ExitScreen(cout).run();
					return;
				}
				break;
			case 3: //Export
				showMenu = true;
				DataHandler::getInstance().runIO();
				if ( !promptContinue() ) {
					DataHandler::getInstance().saveQuizData();
					ExitScreen(cout).run();
					return;
				}
				break;
			case 4: //End
				DataHandler::getInstance().saveQuizData();
				ExitScreen(cout).run();
				return;
			default: showMenu = false;
				cout << "Wrong choice, try again." << endl;
		}

	}
}

bool MainMenuScreen::promptContinue() {
	string dummy = "";
	cout << COLOR_GREEN << "Do you want to continue?" << COLOR_RESET << endl;
	while ( dummy != "yes" && dummy != "no" ) {
		cout << "Write \"yes\" or \"no\"" << endl;
		cin >> dummy;
		if ( dummy == "yes" ) {
			return true;
		} else if ( dummy == "no" ) {
			return false;
		}
	}
	return true;
}

void MainMenuScreen::show() {
	mOs << COLOR_BLUE << "MAIN MENU" << COLOR_RESET << endl;
	cout << COLOR_GREEN << "Choose your activity:\n" << COLOR_RESET <<
	     "\ta) Play game\n"
	     "\tb) Add quiz\n"
	     "\tc) Export/Import quiz\n"
	     "\td) Exit game\n";
}

int MainMenuScreen::promptMainMenu() {
	std::string input;
	cout << COLOR_RED << "Choose, what you want to do by writing a single character." << COLOR_RESET << endl;
	std::cin >> input;
	if ( input.size() > 1 ) {
		return -1;
	}
	switch ( input[0] ) {
		case 'a': return 1;
		case 'b': return 2;
		case 'c': return 3;
		case 'd': return 4;
		case 'e': return 5;
		default: return -1;
	}
}

void MainMenuScreen::welcomeUser() {
	cout << " \\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|\n"
	        "  \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   \n"
	        "   \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  \n"
	        "    \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ \n"
	        "     \\/  \\/   |______|______\\_____\\____/|_|  |_|______|\n"
	        "                                                       \n";
}

void MainMenuScreen::interact() {

}
