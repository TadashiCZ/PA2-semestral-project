//
// Created by Tadeáš Valenta on 28.5.18.
//

#include <fstream>
#include "Importer.hpp"


#define CHECK_READ_FILE if ( inputFile . fail()) {cout << "Read from file failed" << endl; return false;}

using namespace std;

bool Importer::loadFromFile(string filename, vector<Quiz> quizzes) {
	std::string input;
	ifstream inputFile( filename );
	CHECK_READ_FILE
	getline( inputFile, input );
	int quizNumber = atoi( input.c_str() );

	for ( int i = 0 ; i < quizNumber ; ++i ) {
		Quiz quiz = Importer::loadQuiz( inputFile );
		if ( quiz.mName.empty() ) {
			return false;
		}
		quizzes.push_back( quiz );
	}

	getline( inputFile, input );

	if ( !input.empty() ) {
		quizzes.clear();
		return false;
	}

	return true;
}

Quiz Importer::loadQuiz(std::ifstream & inputFile) {
	string dummy;
	getline( inputFile, dummy );
	if ( dummy != "Quiz" ) {
		return Quiz();
	}
	Quiz quiz;
	getline( inputFile, quiz.mName );
	getline( inputFile, quiz.mAuthor );
	int pageCount;
	getline( inputFile, dummy );
	pageCount = atoi( dummy.c_str() );

	loadTree( inputFile, quiz, pageCount );

	for ( int i = 0 ; i < pageCount ; ++i ) {
		quiz.mPages[i].get()->mQuestions = Importer::loadPageQuestions( inputFile );
	}


	return quiz;
}

bool Importer::loadTree(ifstream & inputFile, Quiz & quiz, int pageCount) {
	quiz.mPages.clear();
	int num1, num2;
	string dummy;

	inputFile >> num1;
	inputFile >> dummy;
	auto pt = std::make_shared<Page>( Page() );
	quiz.mPages.emplace_back( pt );
	for ( int i = 0 ; i < pageCount ; ++i ) {
		inputFile >> num1;
		if ( num1 != i ) {
			return false;
		}
		inputFile >> dummy;
		inputFile >> num2;
		inputFile >> dummy;
		quiz.mPages[num2].get()->mBranches.push_back(quiz.mPages[i]);
	}

	return true;
}

std::vector<shared_ptr<Question>> Importer::loadPageQuestions(ifstream & inputFile) {
	//todo
	return vector<shared_ptr<Question>>();
}

shared_ptr<Question> Importer::loadQuestion(ifstream & inputFile) {
	return shared_ptr<Question>();
}
