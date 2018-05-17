#include <iostream>
#include <fstream>
#include <memory>
#include "UI/Menu.h"
#include "Game/Quiz.h"
#include "Game.h"
#include "Game/Question/TrueFalseQuestion.h"

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

	TrueFalseQuestion * question1 = new TrueFalseQuestion( 0, "Is 5+5=10?", true );
	TrueFalseQuestion * question2 = new TrueFalseQuestion( 0, "Is 1+5=10?", false );
	TrueFalseQuestion * question3 = new TrueFalseQuestion(0, "This quiz is cool.", true);
	TrueFalseQuestion * question4 = new TrueFalseQuestion(0, "Eiffel tower is 300 m tall.", true);
	TrueFalseQuestion * question5 = new TrueFalseQuestion(0, "Mariana trench is 10 994 m deep.", true);
	std::cout << question1->exportIntoFileFormat();
	std::vector<Question *> questions;
	std::vector<Question*> questions2;
	questions.push_back( question1 );
	questions.push_back( question2 );

	questions2.push_back( question3 );
	questions2.push_back( question4 );
	questions2.push_back( question5 );

	std::vector<Page *> pages;



	Page * page2 = new Page( questions2 );
	std::vector<Page*> branches; branches.push_back(page2);
	Page * page1 = new Page( questions, branches  );
	pages.push_back( page1 );
	pages.push_back( page2 );

	quizzes.push_back( Quiz( "Medicine", "Anna", pages ) );
	quizzes.push_back( Quiz( "C++", "Frank", pages ) );
	quizzes.push_back( Quiz( "Physiology", "Anna", pages ) );
	loadQuizes( quizzes, "quizzes.dat" );

	welcomeUser();

	bool looping = true;
	Menu().showMainMenu();
	while ( looping ) {
		switch ( Menu().promptMainMenu() ) {
			case 1: // Play
				Game( quizzes ).play();
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
			default: std::cout << "Wrong choice, try again." << std::endl;
		}

	}

	delete page1;
	delete page2;
	delete question1;
	delete question2;
	delete question3;
	delete question4;
	delete question5;
	return 0;
}

