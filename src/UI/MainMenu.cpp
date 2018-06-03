//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "MainMenu.hpp"
#include "../Constants.hpp"
#include "../Game/Game.hpp"
#include "../IO/DataHandler.hpp"

using namespace std;

void MainMenu::run( DataHandler data ) {
	MainMenu::welcomeUser();
	bool looping = true;
	bool showMenu = false;
	MainMenu::show();
	while ( looping ) {
		if ( showMenu ) MainMenu::show();
		switch ( MainMenu::promptMainMenu() ) {
			case 1: // Play
				showMenu = true;
				Game( data.mQuizzes ).play();
				if ( !promptContinue() ) {
					MainMenu::goodbye();
					return;
				}
				break;
			case 2: // Add
				showMenu = true;
				//startAdd();
				break;
			case 3: //Edit
				showMenu = true;
				//startEdit();
				break;
			case 4: //Export
				showMenu = true;
				DataHandler( data.mQuizzes ).runIO();
				break;
			case 5: //End
				// saveIntoFile();
				return;
			default: showMenu = false;
				cout << "Wrong choice, try again." << endl;
		}

	}
}

void goodbye(){
	cout << COLOR_RED << "Saving quizzes." << COLOR_RESET << endl;

	cout << COLOR_CYAN << "Goodbye and thanks for playing." << COLOR_RESET << endl;

}

bool MainMenu::promptContinue() {
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

void MainMenu::show() {
	cout << COLOR_GREEN << "Choose your activity:\n" << COLOR_RESET <<
	     "\ta) Play game\n"
	     "\tb) Add quiz\n"
	     "\tc) Edit quiz\n"
	     "\td) Export/Import quiz\n"
	     "\te) Exit game\n";
}

int MainMenu::promptMainMenu() {
	std::string input;
	printf( "Choose, what you want to do by writing a single character.\n" );
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

void MainMenu::welcomeUser() {
	printf( " \\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|\n"
	        "  \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   \n"
	        "   \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  \n"
	        "    \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ \n"
	        "     \\/  \\/   |______|______\\_____\\____/|_|  |_|______|\n"
	        "                                                       \n" );
}
