//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_GAME_H
#define SEMESTRAL_PROJECT_GAME_H

#include <iostream>
#include "Game/Quiz.h"

unsigned long showQuizListPrompt(const unsigned long size) {
	unsigned long input;
	std::cout << "Choose quiz by writing the quiz number." << std::endl;
	while ( true ) {
		std::string dummy;
		std::cin.clear();
		std::cin >> dummy;
		if (dummy == "exit"){
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

class Game {
public:
	explicit Game(std::vector<Quiz> & quizzes) : mQuizzes( quizzes ) {}

	int showQuizList() {
		std::cout << std::endl << "Quiz list:" << std::endl;
		for ( size_t i = 0 ; i < mQuizzes.size() ; ++i ) {
			std::cout << i + 1 << ") " << mQuizzes[i].printQuizListInfo() << std::endl;
		}
		return showQuizListPrompt( mQuizzes.size() );

	}

	void play() {
		int score = 0, possibleScore = 0;
		if ( mQuizzes[showQuizList()].play( score, possibleScore ) ) {
			// success, show score/possibleScore
		} else {
			// you failed, you die
		}


	}


protected:
	std::vector<Quiz> & mQuizzes;


};

#endif //SEMESTRAL_PROJECT_GAME_H
