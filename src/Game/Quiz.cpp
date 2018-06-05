//
// Created by Tadeáš Valenta on 1.6.18.
//

#include "Quiz.hpp"
#include "../Constants.hpp"

using namespace std;

Quiz::Quiz(string name) : mName( name ) {}

Quiz::Quiz(const string & quizName, const string & authorName, vector<shared_ptr<Page>> & pages)
		: mName( quizName ), mAuthor( authorName ), mPages( pages ) {}

Quiz::Quiz(const Quiz & quiz) {
	mAuthor = quiz.mAuthor;
	mName = quiz.mName;
	mPages.clear();

	for ( const auto & page : quiz.mPages ) {
		mPages.push_back( page );
	}
}

string Quiz::printQuizListInfo() {
	string output;
	output.append( mName ).append( " (by " ).append( mAuthor ).append( ")" );
	return output;
}

string Quiz::exportQuizIntoFile() {
	string output;
	output.append( "Quiz\n" ).append( mName ).append( "\n" ).append( mAuthor ).append( "\n" );
	output.append( to_string( mPages.size() ) ).append( "\n" );
	output.append( printTree() );
	for ( size_t i = 0 ; i < mPages.size() ; ++i ) {
		output.append( mPages[i]->exportPageIntoFile( i ) );
	}
	return output;
}

std::string Quiz::printTree() {
	string output;
	output.append( "Tree:\n0,x\n" );
	for ( size_t j = 0 ; j < mPages.size() ; ++j ) {
		if ( mPages[j]->mBranches[0] ) {
			for ( size_t i = 0 ; i < mPages.size() ; ++i ) {
				if ( mPages[j]->mBranches[0].get() == mPages[i].get() ) {
					output.append( to_string( i ) ).append( "," ).append( to_string( j ) ).append( "\n" );
				}
			}
		}
		// todo invalid read
		if ( mPages[j]->mBranches[1] ) {
			for ( size_t i = 0 ; i < mPages.size() ; ++i ) {
					if ( mPages[j]->mBranches[1] == mPages[i] ) {
						output.append( to_string( i ) ).append( "," ).append( to_string( j ) ).append( "\n" );
					}
			}
		}
	}
	return output;
}

string Quiz::printPageList() {
	string output;
	output.append( printTree() ).append( "\n" );
	for ( size_t i = 0 ; i < mPages.size() ; ++i ) {

		output.append( COLOR_BLUE ).append( "Page with ID No. " ).append( to_string( i + 1 ) ).append( ": \n" ).append(
				COLOR_RESET );
		output.append( mPages[i]->printQuestionList() ).append( "\n" );
	}
	return output;
}

bool Quiz::operator==(Quiz & quiz) {
	for ( size_t i = 0 ; i < mPages.size() ; ++i ) {
		if ( !( *mPages[i] == *quiz.mPages[i] ) ) {
			return false;
		}
	}

	return true;
}

