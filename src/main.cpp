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

	std::unique_ptr<Question> q1 = std::make_unique<Question>( TrueFalseQuestion( 0, "Is 5+5=10?", true ) );
	auto q2 = std::make_unique<Question>( TrueFalseQuestion( 0, "Is 1+5=10?", false ) );
	auto q3 = std::make_unique<Question>( TrueFalseQuestion( 0, "This quiz is cool.", true ) );
	auto q4 = std::make_unique<Question>( TrueFalseQuestion( 0, "Eiffel tower is 300 m tall.", true ) );
	auto q5 = std::make_unique<Question>( TrueFalseQuestion( 0, "Mariana trench is 10 994 m deep.", true ) );
	std::cout << q1->exportIntoFileFormat();
	std::vector<std::unique_ptr<Question>> questions;
	std::vector<std::unique_ptr<Question>> questions2;
	questions.push_back( std::move( q1 ) );
	questions.push_back( std::move( q2 ) );

	questions2.push_back( std::move( q3 ) );
	questions2.push_back( std::move( q4 ) );
	questions2.push_back( std::move( q5 ) );

	std::vector<std::unique_ptr<Page>> pages;

	auto page2 = std::make_unique<Page>( questions2 );
	std::vector<std::unique_ptr<Page>> branches;
	branches.push_back( std::move( page2 ) );
	auto page1 = std::make_unique<Page>( questions, branches );
	pages.push_back( std::move( page1 ) );
	pages.push_back( std::move( page2 ) );

	quizzes.emplace_back( "Medicine", "Anna", pages );
	quizzes.emplace_back( "C++", "Frank", pages );
	quizzes.emplace_back( "Physiology", "Anna", pages );
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
	return 0;
}

