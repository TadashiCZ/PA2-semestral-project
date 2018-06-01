//
// Created by tadashicz on 1.6.18.
//

#include <sstream>
#include "Page.hpp"

using namespace std;

Page::Page() {}

Page::Page(vector<shared_ptr<Question>> & questionList) : mQuestions( questionList ),
                                                                    mBranches( vector<shared_ptr<Page>>{nullptr} ) {}

Page::Page(vector<shared_ptr<Question>> & questionList, vector<shared_ptr<Page>> & branches)
		: mQuestions( questionList ), mBranches( branches ) {}

Page::Page(const Page & page) {
	mBranches.clear();
	mQuestions.clear();

	for ( auto it = page.mQuestions.begin() ; it != page.mQuestions.end() ; ++it ) {
		mQuestions.push_back( *it );
	}
	for ( auto it = page.mBranches.begin() ; it != page.mBranches.end() ; ++it ) {
		mBranches.push_back( *it );
	}
}

Page * Page::play(int & score, int & scorePossible) {
	for ( auto it = mQuestions.begin() ; it != mQuestions.end() ; ++it ) {
		cout << ( **it ).printQuestion() << endl;
		cout << ( **it ).printHint() << endl;
		if ( ( **it ).evaluate() ) {
			score++;
			scorePossible++;
			cout << "Correct!" << endl << endl;
			if ( this->isBranching && *it == mQuestions.back() ) {
				cout << "Current score: " << score << "/" << scorePossible << endl;
				cout << "End of page. Press Enter to continue..." << endl;
				cin.get();
				cin.get();
				return mBranches[0].get();
			}
		} else {
			scorePossible++;
			cout << "Wrong, good luck with the next one." << endl << endl;
			if ( this->isBranching && *it == mQuestions.back() ) {
				cout << "Current score: " << score << "/" << scorePossible << endl;
				cout << "End of page. Press Enter to continue..." << endl;
				cin.get();
				cin.get();
				return mBranches[1].get();
			}
		}
	}


	cout << "Current score: " << score << "/" << scorePossible << endl;
	cout << "End of page. Press Enter to continue..." << endl;
	cin.get();
	cin.get();
	return mBranches[0].get(); // return branch which one should go to
}

string Page::exportPage() {
	string output;
	stringstream ss;

	ss << mQuestions.size();
	output.append( "Page\nQuestionCount:" ).append( ss.str() );
	output.append( ";BranchCount:" ).append( BoolToStringNumber( mBranches.size() == 2 ) ).append( "\n" );
	for ( shared_ptr<Question> quest : mQuestions ) {
		output.append( quest->exportIntoFileFormat() );
	}
	output.append( "\n" );
	return output;
}
