//
// Created by Tadeáš Valenta on 28.5.18.
//

#include "ExpoImpo.hpp"
#include "Importer.hpp"
#include "Exporter.hpp"
#include <fstream>

ExpoImpo::ExpoImpo(std::vector<Quiz> & quizzes) : mQuizzes( quizzes ) {
	run();
}

int ExpoImpo::IOMenu() {
	std::cout << "Do you want to import or export quizzes? Write it. (Or write \"exit\" if you want to go back.)"
	          << std::endl;
	while ( true ) {
		std::string dummy;
		std::cin.clear();
		std::cin >> dummy;
		if ( dummy == "exit" ) {
			return -1;
		} else if ( dummy == "import" ) {
			return 1;
		} else if ( dummy == "export" ) {
			return 2;
		} else {
			std::cout << "Not like this. Write \"import\", \"export\" or \"exit\"." << std::endl;
		}
	}
}

bool ExpoImpo::checkInputFilename(std::string & input) {
	//todo checkInputFilename
	return true;
}

bool ExpoImpo::exportQuizzes() {




	return true;
}

void ExpoImpo::run() {
	switch ( IOMenu() ) {
		case 1:
			importQuizzes();
			break;
		case 2:
			exportQuizzes();
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
	std::string inputFileName = ExpoImpo::promptFilename();
	return Importer::loadFromFile( inputFileName, mQuizzes );
}

