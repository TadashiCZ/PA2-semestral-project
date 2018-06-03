//
// Created by Tadeáš Valenta on 1.6.18.
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
		cout << ( **it ).printFullQuestion() << endl;
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

string Page::exportPageIntoFile(int pageNumber) {
	string output;
	output.append( "Page\n" ).append( to_string( pageNumber ) ).append( "\n" );
	output.append( to_string( mQuestions.size() ) ).append( "\n" ).append( BoolToStringNumber( isBranching ) ).append( "\n" );
	for ( const auto & quest : mQuestions ) {
		output.append( quest->exportIntoFileFormat() );
	}
	return output;
}

string Page::printQuestionList() {
	string output;
	for ( size_t i = 0 ; i < mQuestions.size() ; ++i ) {
		output.append(to_string(i+1)).append(") ").append(mQuestions[i]->printQuestion()).append("\n");
	}

	return output;
}
