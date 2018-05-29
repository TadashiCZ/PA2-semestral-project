//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include <sstream>
#include "Page.hpp"

class Quiz {
public:

	Quiz(std::string name = ""):mName(name){}

	Quiz(const std::string & quizName, const std::string & authorName, std::vector<std::shared_ptr<Page>> & pages)
			: mName( quizName ), mAuthor( authorName ), mPages( pages ) {}

	Quiz(const Quiz & quiz) {
		mAuthor = quiz.mAuthor;
		mName = quiz.mName;
		mPages.clear();

		for ( auto it = quiz.mPages.begin() ; it != quiz.mPages.end() ; ++it ) {
			mPages.push_back( *it );
		}
	}

	bool play(int & score, int & scorePossible) {
		std::cout << std::endl << "You are playing quiz " << mName << " from " << mAuthor << "." << std::endl;
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
		os << mName << " (by " << mAuthor << ")";
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


	std::string mName;
	std::string mAuthor;
	std::vector<std::shared_ptr<Page>> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H
