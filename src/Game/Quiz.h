//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include <sstream>
#include "Page.h"

class Quiz {
public:
	Quiz(const std::string & quizName, const std::string & authorName) : mQuizName( quizName ), mAuthor( authorName ) {}

	Quiz(const Quiz & quiz) {
		mAuthor = quiz.mAuthor;
		mQuizName = quiz.mQuizName;
		for ( Page * page : mPages ) {
			delete page;
		}
		mPages.clear();

		for ( Page * page : quiz.mPages ) {
			mPages.push_back( page );
		}
	}

	bool play(int & score, int & scorePossible) {
		std::cout << std::endl << "You are playing quiz " << mQuizName << " from " << mAuthor << "." << std::endl;
		//todo gameplay


	}

	std::string printQuizListInfo() {
		std::ostringstream os;
		os << mQuizName << " (by " << mAuthor << ")";
		std::string output = os.str();
		return output;
	}

	std::string & print();


protected:
	std::string mQuizName;
	std::string mAuthor;

	std::vector<Page *> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H
