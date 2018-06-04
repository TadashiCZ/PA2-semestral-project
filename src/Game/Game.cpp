//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "Game.hpp"
#include "../Database/DataHandler.hpp"

using namespace std;
Game::Game(Quiz & quiz) : mQuiz( quiz ) {}



void Game::play(ostream & os) {
	int score = 0, scorePossible = 0;

	os << endl << "You are playing quiz " << mQuiz.mName << " from " << mQuiz.mAuthor << "." << endl;
	Page * nextPage = mQuiz.mPages[0].get();
	do {
		nextPage = nextPage->play( score, scorePossible );
	} while ( nullptr != nextPage );

	os << "You finished the quiz with score " << score << " from " << scorePossible << " possible." << endl
	     << endl;


}

