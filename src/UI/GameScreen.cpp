/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#include <iostream>
#include "GameScreen.hpp"
#include "../Database/DataHandler.hpp"
#include "../Game/Game.hpp"
#include "ExitScreen.hpp"
#include "../Constants.hpp"

using namespace std;

GameScreen::GameScreen(ostream & os) : mOs( os ) {}

void GameScreen::show() {
	mOs << COLOR_BLUE << "PLAY GAME" << COLOR_RESET << endl;
}

void GameScreen::interact(){
	showQuizList();
}

void GameScreen::run() {
	show();
	interact();
}

void GameScreen::showQuizList() {
	mOs << endl << "Quiz list:" << endl;
	for ( size_t i = 0 ; i < DataHandler::getInstance().mQuizzes.size() ; ++i ) {
		mOs << i + 1 << ") " << DataHandler::getInstance().mQuizzes[i].printQuizListInfo() << endl;
	}
	showQuizListPrompt( DataHandler::getInstance().mQuizzes.size() );
}

void GameScreen::showQuizListPrompt(const unsigned long size) {
	unsigned long input;
	mOs << "Choose quiz by writing the quiz number." << endl;
	while ( true ) {
		string dummy;
		cin.clear();
		cin >> dummy;
		if ( dummy == "exit" ) {
			return;
		}
		input = atoi( dummy.c_str() );
		if ( input > 0 && input <= size ) {
			mOs << "Okay, you choose quiz no. " << input << "." << endl;
			Game( DataHandler::getInstance().mQuizzes[input-1] ).play(cout);
			return;
		} else {
			mOs << "Out of bounds, try again." << endl;
		}
	}
}