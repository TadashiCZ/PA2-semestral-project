//
// Created by Tadeáš Valenta on 28.5.18.
//

#include <fstream>
#include "Importer.hpp"

#define CHECK_READ_FILE if ( inputFile . fail()) {cout << "Read from file failed" << endl; return false;}
#define EMPTY_VECTOR vector<Quiz>()
#define CHECK_WRITE_FILE if ( outputFile . fail()) {cout <<"Write to file failed" << endl; return false;}

using namespace std;

bool Importer::loadFromFile(string filename, vector<Quiz> quizzes) {
	std::string input;
	ifstream inputFile( filename );
	CHECK_READ_FILE
	getline( inputFile, input );
	int quizNumber = atoi( input.c_str() );

	for ( int i = 0 ; i < quizNumber ; ++i ) {
		Quiz quiz = loadQuiz( inputFile );
		if ( quiz.mName.empty() ) {
			return false;
		}
		quizzes.push_back( quiz );
	}
	return true;
}

Quiz Importer::loadQuiz(ifstream & inputString) {
	Quiz quiz;
	string input;
	getline(inputString, input);
	if (input.c_str() != "Quiz"){
		quiz.mName = "";
		return quiz;
	}

	getline(inputString, quiz.mName);
	getline(inputString, quiz.mAuthor);

	getline(inputString, input);
	int pageCount = atoi(input.c_str());

	loadTree(pageCount);

	for ( int i = 0 ; i <  pageCount; ++i ) {
		loadPage()
	}

	return quiz;
}

Page Importer::loadPage(ifstream & inputString) {
	return Page();
}

shared_ptr<Question> Importer::loadQuestion(ifstream & inputString) {
	return shared_ptr<Question>();
}
