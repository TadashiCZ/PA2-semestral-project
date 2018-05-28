//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include <sstream>
#include "Page.h"

class Quiz {
public:
	Quiz(const std::string & quizName, const std::string & authorName, std::vector<std::shared_ptr<Page>> & pages)
			: mQuizName( quizName ), mAuthor( authorName ), mPages( pages ) {}

	Quiz(const Quiz & quiz) {
		mAuthor = quiz.mAuthor;
		mQuizName = quiz.mQuizName;
		mPages.clear();

		for ( auto it = quiz.mPages.begin() ; it != quiz.mPages.end() ; ++it ) {
			mPages.push_back( *it );
		}
	}

	bool play(int & score, int & scorePossible) {
		std::cout << std::endl << "You are playing quiz " << mQuizName << " from " << mAuthor << "." << std::endl;
		Page * nextPage = mPages[0].get();
		do {
			nextPage = nextPage->play( score, scorePossible );
		} while ( nullptr != nextPage );

		std::cout << "You finished the quiz with score " << score << " from " << scorePossible << " possible." << std::endl
		          << std::endl;

		return true;
	}

	std::string printQuizListInfo() {
		std::ostringstream os;
		os << mQuizName << " (by " << mAuthor << ")";
		std::string output = os.str();
		return output;
	}

	std::string exportQuiz() {
		std::string output;
		for ( std::shared_ptr<Page> page : mPages ) {
			output.append( page->exportPage() );
		}
		return output;
	}

	std::string & print();


protected:
	std::string mQuizName;
	std::string mAuthor;
	std::vector<std::shared_ptr<Page>> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H