#include <iostream>
#include <fstream>
#include <memory>
#include "UI/Menu.h"
#include "Game/Quiz.h"
#include "Game.h"
#include "Game/Question/TrueFalseQuestion.h"
#include "Game/Question/TextQuestion.h"
#include "Game/Question/MultiChoiceQuestion.h"

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

	auto q1 = std::make_shared<TrueFalseQuestion>( 0, "Is 5+5=10?", true );
	auto q2 = std::make_shared<TrueFalseQuestion>( 0, "Is 1+5=10?", false );
	auto q3 = std::make_shared<TextQuestion>( 0, "This quiz is cool.", "Yes" );
	auto q4 = std::make_shared<TrueFalseQuestion>( 0, "Eiffel tower is 300 m tall.", true );
	auto q5 = std::make_shared<TrueFalseQuestion>( 0, "Mariana trench is 10 994 m deep.", true );
	q2->setBranching( true );
	std::cout << q5->isBranching() << std::endl;
	std::vector<std::pair<std::string, bool>> choices6 = {std::make_pair( "Green", false ), std::make_pair( "White", false ),
	                                                      std::make_pair( "Blue", true ), std::make_pair( "Yellow", true )};
	std::vector<std::pair<std::string, bool>> choices7 = {std::make_pair( "Green", false ), std::make_pair( "White", true ),
	                                                      std::make_pair( "Blue", true ), std::make_pair( "Yellow", false )};
	auto q6 = std::make_shared<MultiChoiceQuestion>( 0, "What colors are on Columbian flag?", choices6 );
	auto q7 = std::make_shared<MultiChoiceQuestion>( 0, "What colors are on Czech flag?", choices7 );

	std::vector<std::shared_ptr<Question>> questions;
	std::vector<std::shared_ptr<Question>> questions2;
	std::vector<std::shared_ptr<Question>> questions3;
	questions.push_back( q1 );
	questions.push_back( q2 );

	questions2.push_back( q3 );
	questions2.push_back( q4 );
	questions2.push_back( q5 );

	questions3.push_back( q6 );
	questions3.push_back( q7 );

	std::vector<std::shared_ptr<Page>> pages;
	auto page3 = std::make_shared<Page>( questions3 );
	auto page2 = std::make_shared<Page>( questions2 );
	std::vector<std::shared_ptr<Page>> branches;
	branches.push_back( page2 );
	branches.push_back( page3 );
	auto page1 = std::make_shared<Page>( questions, branches );
	pages.push_back( page1 );
	pages.push_back( page2 );

	quizzes.emplace_back( Quiz( "Medicine", "Anna", pages ) );
	quizzes.emplace_back( Quiz( "C++", "Frank", pages ) );
	quizzes.emplace_back( Quiz( "Physiology", "Anna", pages ) );
	loadQuizes( quizzes, "quizzes.dat" );

	welcomeUser();

	bool looping = true;
	Menu().showMainMenu();
	while ( looping ) {
		switch ( Menu().promptMainMenu() ) {
			case 1: // Play
				Game( quizzes ).play();
				Menu().showMainMenu();
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

