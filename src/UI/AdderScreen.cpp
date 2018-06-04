/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#include <algorithm>
#include "AdderScreen.hpp"
#include "../Constants.hpp"

using namespace std;

AdderScreen::AdderScreen(std::ostream & os) : mOs( os ) {}

void AdderScreen::run() {
	show();
	interact();

}

void AdderScreen::show() {
	mOs << COLOR_BLUE << "QUIZ ADDER 2000" << COLOR_RESET << endl;
}

void AdderScreen::interact() {
	mOs << COLOR_YELLOW << "So you would like to create a quiz? (yes/no)" << COLOR_RESET << endl;
	while ( true ) {
		int num = yesNoInput();
		if ( num == 1 ) {
			break;
		} else if ( num == 0 ) {
			return;
		} else {
			mOs << "Just write yes or no. Nothing hard." << endl;
			continue;
		}
	}
	Quiz quiz;
	mOs << COLOR_YELLOW << "Okay! Let's do it! What will be the name of the quiz?" << COLOR_RESET << endl;
	quiz.mName = promptString();
	mOs << COLOR_YELLOW << quiz.mName << "? Great name for a quiz. And what is your name?" << COLOR_RESET << endl;
	quiz.mAuthor = promptString();
	mOs << COLOR_YELLOW << "Well nice to meet you " << quiz.mAuthor << "." << endl
	    << "And now something little bit more complicated. Structure of the quiz. But don't worry, I'll help you." << COLOR_RESET
	    << endl;
	loadTreeInteractive( quiz );
}

int AdderScreen::yesNoInput() {
	string dummy;
	cin >> dummy;
	transform( dummy.begin(), dummy.end(), dummy.begin(), ::tolower );
	if ( dummy == "yes" ) {
		return 1;
	} else if ( dummy == "no" ) {
		return 0;
	} else {
		return -1;
	}
}

std::string AdderScreen::promptString() {
	std::string dummy = "";
	while ( dummy.empty() ) {
		cin >> dummy;
	}
	return dummy;
}

void AdderScreen::loadTreeInteractive(Quiz & quiz) {
	string dummy; char c = ' ';
	int num1 = 1, num2 = 100, pageCount = 0;
	mOs << COLOR_YELLOW << "How many pages you quiz will have?" << COLOR_RESET << endl;

	while ( pageCount == 0 ) {
		cin >> pageCount;
	}
	mOs << COLOR_YELLOW << "Your quiz will have " << pageCount << " pages." << endl
	    << "Now the quiz tree. You will start with the root page 0 by writing \"0,x\"" << endl
	    << "Try it now." << COLOR_RESET << endl;


	while ( num1 != 0 || dummy != ",x" ) {
		cin >> num1 >> dummy;
		if ( num1 == 0 && dummy == ",x" ) {
			mOs << COLOR_YELLOW << "Great!" << COLOR_RESET << endl;
			break;
		}
		mOs << COLOR_YELLOW << "Are you really trying? 0,x and nothing more." << COLOR_RESET << endl;
	}
	if ( pageCount > 1 ) {
		mOs << COLOR_YELLOW << "And now you will put first the page number, comma and then the parent of that page." << endl
		    << "But make sure you input them from the lowest to the highest (0,1,2,..) and don't omit any. I will tell you when it's enough. :)"
		    << COLOR_RESET << endl;
	} else {
		// todo loadPage
	}
	quiz.mPages.clear();
	auto pt = make_shared<Page>();
	quiz.mPages.emplace_back( pt );

	for ( int i = 1 ; i < pageCount ; ++i ) {
		while ( num1 != i || c != ',' || num2 >= i) {
			cin >> num1 >> c >> num2;
			if ( num1 == i && c == ',' && num2 < i) {
				mOs << COLOR_YELLOW << "Great! I now know about this relationship." << COLOR_RESET << endl;
				break;
			}
			mOs << COLOR_RED << "num1: " << num1 << "/ num2: " << num2 << "/ char: " << c << endl;
			mOs << COLOR_YELLOW << "Not like this. Try again." << COLOR_RESET << endl;
		}
		auto ptr = make_shared<Page>();
		quiz.mPages.emplace_back( ptr );
		quiz.mPages[num2]->mBranches.push_back( quiz.mPages[i] );
	}

		for ( int i = 1 ; i < pageCount ; ++i ) {
		switch ( quiz.mPages[i]->mBranches.size() ) {
			case 0: quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				break;
			case 1: quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				break;
			default: break;
		}

	}

}

