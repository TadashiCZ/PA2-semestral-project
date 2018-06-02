//
// Created by tadashicz on 1.6.18.
//

#include <iostream>
#include <fstream>
#include "Exporter.hpp"


#define CHECK_READ_FILE if ( outputFile . fail()) {cout << "Read from file failed" << endl; return false;}

using namespace std;

bool Exporter::exportToFile(std::string filename, std::vector<Quiz> & quizzes) {
	ofstream outputFile( filename );
	CHECK_READ_FILE
	outputFile << quizzes.size() << endl;
	for ( auto & quiz : quizzes ) {
		outputFile << quiz.exportQuizIntoFile();
	}
	return true;
}