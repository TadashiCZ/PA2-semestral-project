#include <iostream>
#include <fstream>
#include <memory>
#include "UI/Menu.hpp"
#include "Game/Quiz.hpp"
#include "Game.hpp"
#include "IO/ExpoImpo.hpp"
#include "IO/Importer.hpp"

void showQuizList();

void welcomeUser() {
	printf( " \\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|\n"
	        "  \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   \n"
	        "   \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  \n"
	        "    \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ \n"
	        "     \\/  \\/   |______|______\\_____\\____/|_|  |_|______|\n"
	        "                                                       \n" );
}

inline bool checkExistence(const char * name) {
	std::ifstream f( name );
	if ( f.good() ) {
		f.close();
		return true;
	} else {
		f.close();
		return false;
	}
}

void loadQuizes(std::vector<Quiz> & quizzes, const char * name) {
	if ( !checkExistence( name ) ) {
		return;
	}

	//todo load from file
}

void playGame(std::vector<Quiz> & quizzes) {

}

int main() {
	std::vector<Quiz> quizzes;
	Importer::loadFromFile( "export.dat", quizzes );

	welcomeUser();
	bool looping = true;
	bool showMenu = true;
	Menu().showMainMenu();
	while ( looping ) {
		switch ( Menu().promptMainMenu() ) {
			case 1: // Play
				if ( showMenu ) Menu().promptMainMenu();
				showMenu = true;
				Game( quizzes ).play();
				break;
			case 2: // Add
				if ( showMenu ) Menu().promptMainMenu();
				showMenu = true;
				//startAdd();
				break;
			case 3: //Edit
				if ( showMenu ) Menu().promptMainMenu();
				showMenu = true;
				//startEdit();
				break;
			case 4: //Export
				if ( showMenu ) Menu().promptMainMenu();
				showMenu = true;
				ExpoImpo( quizzes ).run();
				break;
			case 5: //End
				// saveIntoFile();
				return 0;
			default: showMenu = false;
				std::cout << "Wrong choice, try again." << std::endl;
		}

	}
	return 0;
}

