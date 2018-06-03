//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "MainMenu.hpp"

void Menu::showMainMenu() {
	printf( "Choose your activity:\n"
	        "a) Play game\n"
	        "b) Add quiz\n"
	        "c) Edit quiz\n"
	        "d) Export/Import quiz\n"
	        "e) Exit game\n" );
}

int Menu::promptMainMenu() {
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
