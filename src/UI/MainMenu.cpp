//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "MainMenu.hpp"
#include "../Constants.hpp"

using namespace std;

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
