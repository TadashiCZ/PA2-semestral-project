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
		//quiz.mPages[i].get()->mQuestions = Importer::loadPageQuestions( inputFile );
	}


	return quiz;
}

bool Importer::loadTree(ifstream & inputFile, Quiz & quiz, int pageCount) {
	char dummy1;
	string dummy;
	int num1, num2;
	cout << "Loading tree, page count: " << pageCount << endl;
	getline(inputFile, dummy);
	if ( dummy != "Tree:"){
		return false;
	}

	quiz.mPages.clear();

	getline(inputFile, dummy);
	cout << dummy << endl;
	num1 = atoi(dummy.c_str());
	if (num1 != 0){
		return false;
	}
	auto pt = make_shared<Page>( );
	quiz.mPages.push_back( pt );
	for ( int i = 1 ; i <= pageCount ; ++i ) {
		inputFile >> num1;
		inputFile >> dummy1;
		inputFile >> num2;

		cout << "num1: " << num1 << ", dummy1: " << dummy1 << ", num2: " << num2 << endl;

		if ( num1 != i ) {
			cout << "Vracim == num1: " << num1 << ", dummy1: " << dummy1 << ", num2: " << num2 << endl;
			return false;
		}
		auto ptr = make_shared<Page>( );
		quiz.mPages.emplace_back( ptr );
		quiz.mPages[num2]->mBranches.push_back(quiz.mPages[i]);
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
