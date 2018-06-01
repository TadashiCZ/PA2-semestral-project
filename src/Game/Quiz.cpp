//
// Created by tadashicz on 1.6.18.
//

#include "Quiz.hpp"

using namespace std;

Quiz::Quiz(string name) :mName(name){}

Quiz::Quiz(const string & quizName, const string & authorName, vector<shared_ptr<Page>> & pages)
		: mName( quizName ), mAuthor( authorName ), mPages( pages ) {}

Quiz::Quiz(const Quiz & quiz) {
	mAuthor = quiz.mAuthor;
	mName = quiz.mName;
	mPages.clear();

	for ( auto it = quiz.mPages.begin() ; it != quiz.mPages.end() ; ++it ) {
		mPages.push_back( *it );
	}
}

bool Quiz::play(int & score, int & scorePossible) {
	cout << endl << "You are playing quiz " << mName << " from " << mAuthor << "." << endl;
	Page * nextPage = mPages[0].get();
	do {
		nextPage = nextPage->play( score, scorePossible );
	} while ( nullptr != nextPage );

	cout << "You finished the quiz with score " << score << " from " << scorePossible << " possible." << endl
	          << endl;

	return true;
}

string Quiz::printQuizListInfo() {
	ostringstream os;
	os << mName << " (by " << mAuthor << ")";
	string output = os.str();
	return output;
}

string Quiz::exportQuiz() {
	string output;
	for ( shared_ptr<Page> page : mPages ) {
		output.append( page->exportPage() );
	}
	return output;
}
