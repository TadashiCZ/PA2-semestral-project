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
	string os;
	os.append(mName).append(" (by ").append(mAuthor).append(")");
	return os;
}

string Quiz::exportQuizIntoFile() {
	string output;
	output.append("Quiz\n").append(mName).append("\n").append(mAuthor).append("\n");
	output.append(to_string(mPages.size())).append("\n");
	//printing tree
	output.append("Tree:\n0,x\n");

	for ( unsigned int j = 0 ; j < mPages.size() ; ++j ) {
		if (mPages[j]->mBranches[0] != nullptr){
			for ( unsigned int i = 0 ; i <  mPages.size(); ++i ) {
				if (mPages[j]->mBranches[0].get() == mPages[i].get()){
					output.append(to_string(i)).append(",").append(to_string(j)).append("\n");
				}
			}
		}

		if (mPages[j]->mBranches[1] != nullptr){
			for ( unsigned int i = 0 ; i <  mPages.size(); ++i ) {
				if (mPages[j]->mBranches[1].get() == mPages[i].get()){
					output.append(to_string(i)).append(",").append(to_string(j)).append("\n");
				}
			}
		}
	}
	// done printing tree
	for ( unsigned int i = 0 ; i <  mPages.size() ; ++i ) {
		output.append( mPages[i]->exportPageIntoFile(i));
	}
	return output;
}
