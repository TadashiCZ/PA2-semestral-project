#include <iostream>
#include <fstream>
#include "UI/Menu.h"
#include "Game/Quiz.h"

void welcomeUser() {
	printf( "\\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|\n"
	        "  \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   \n"
	        "   \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  \n"
	        "    \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ \n"
	        "     \\/  \\/   |______|______\\_____\\____/|_|  |_|______|\n"
	        "                                                       " );
}

inline bool checkExistence(const char * name) {
	std::ifstream f( name );
	return f.good();
}

void loadQuizes(std::vector<Quiz> & quizes, const char * name) {
	if ( !checkExistence( name ) ) {
		return;
	}

	//todo load from file
}

void playGame(std::vector<Quiz> & quizes){

}

int main() {
	std::vector<Quiz> quizes;

	loadQuizes( quizes, "quizes.dat" );

	welcomeUser();

	bool looping = true;
	Menu().showMainMenu();
	while ( looping ) {
		switch ( Menu().promptMainMenu() ) {
			case 1: // Play
				playGame( quizes );
				looping = false;
				break;
			case 2: // Add
				//startAdd();
				looping = false;
				break;
			case 3: //Edit
				//startEdit();
				looping = false;
				break;
			case 4: //Export
				//startExport();
				looping = false;
				break;
			case 5: //End
				// saveIntoFile();
				return 0;
			default: printf( "Wrong choice, try again\n" );
		}

	}
	return 0;
}

