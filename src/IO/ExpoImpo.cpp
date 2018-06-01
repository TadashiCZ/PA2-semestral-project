//
// Created by Tadeáš Valenta on 28.5.18.
//

#include "ExpoImpo.hpp"
#include "Importer.hpp"
#include <iostream>
#include <fstream>

ExpoImpo::ExpoImpo(std::vector<Quiz> & quizzes) : mQuizzes( quizzes ) {}

int ExpoImpo::importOrExport() {
	std::cout << "Do you want to import or export quizzes? Write it. (Or write \"exit\" if you want to go back.)"
	          << std::endl;
	while ( true ) {
		std::string dummy;
		std::cin.clear();
		std::cin >> dummy;
		if ( dummy == "exit" ) {
			return -1;
		} else if ( dummy == "import" ) {
			return 0;
		} else if ( dummy == "export" ) {
			return 1;
		} else {
			std::cout << "Not like this. Write \"import\", \"export\" or \"exit\"." << std::endl;
		}
	}
}
bool ExpoImpo::checkInputFilename(std::string & input) {
	//todo
	return true;
}

bool ExpoImpo::exportQuizzes() {
	for ( Quiz & quiz :mQuizzes ) {
		quiz.exportQuizIntoFile();
	}
	return true;
}

void ExpoImpo::run() {
	switch ( importOrExport() ) {
		case 0:
			//importQuizzes();
			break;
		case 1:
			//exportQuizzes();
			break;
		case -1: return;
	}

}

std::string ExpoImpo::promptFilename() {
	std::cout << "Write complete filepath to file with quizzes you want to import." << std::endl;
	std::string input;
	while ( true ) {
		std::cin >> input;
		if ( !input.empty() && checkInputFilename( input ) ) {
			return input;
		} else {
			std::cout << "Wrong input, try again." << std::endl;
		}
	}
}



bool ExpoImpo::importQuizzes() {
	//todo import from file
	std::string inputFileName = ExpoImpo::promptFilename();
	std::ofstream ofs( inputFileName, std::ios::out );
	if ( ofs.fail() ) {
		std::cout << "Failed to open file for writing." << std::endl;
		return false;
	}

	return Importer::loadFromFile( inputFileName, mQuizzes);
}

