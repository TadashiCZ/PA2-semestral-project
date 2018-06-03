//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "Game.hpp"
#include "../IO/DataHandler.hpp"

int Game::showQuizList() {
	std::cout << std::endl << "Quiz list:" << std::endl;
	for ( size_t i = 0 ; i < DataHandler::getInstance().mQuizzes.size() ; ++i ) {
		std::cout << i + 1 << ") " << DataHandler::getInstance().mQuizzes[i].printQuizListInfo() << std::endl;
	}
	return showQuizListPrompt( DataHandler::getInstance().mQuizzes.size() );

}

void Game::play() {
	int score = 0, possibleScore = 0;
	if ( DataHandler::getInstance().mQuizzes[showQuizList()].play( score, possibleScore ) ) {
		// success, show score/possibleScore
	} else {
		// you failed, you die
	}
}

//todo rewrite without cout
unsigned long showQuizListPrompt(const unsigned long size) {
	unsigned long input;
	std::cout << "Choose quiz by writing the quiz number." << std::endl;
	while ( true ) {
		std::string dummy;
		std::cin.clear();
		std::cin >> dummy;
		if ( dummy == "exit" ) {
			//todo
		}
		input = atoi( dummy.c_str() );
		if ( input > 0 && input <= size ) {
			std::cout << "Okay, you choose quiz no. " << input << "." << std::endl;
			return input - 1;
		} else {
			std::cout << "Out of bounds, try again." << std::endl;
		}
	}
}
