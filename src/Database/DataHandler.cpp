//
// Created by Tadeáš Valenta on 28.5.18.
//

#include "DataHandler.hpp"
#include "Importer.hpp"
#include <fstream>

int DataHandler::IOMenu() {
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

bool DataHandler::exportQuizzes() {
	// todo export chosen quizzes - last job?
	return true;
}

void DataHandler::runIO() {
	switch ( IOMenu() ) {
		case 1: importQuizzes();
			break;
		case 2: exportQuizzes();
			break;
		case -1: return;
	}

}

std::string DataHandler::promptFilename() {
	std::cout << "Write relative filepath to file with quizzes you want to import." << std::endl;
	std::string input;
	while ( true ) {
		std::cin >> input;
		if ( !input.empty() ) {
			return input;
		} else {
			std::cout << "Wrong input, try again." << std::endl;
		}
	}
}

bool DataHandler::importQuizzes() {
	std::string inputFileName = DataHandler::promptFilename();
	return Importer::loadFromFile( inputFileName, mQuizzes );
}

DataHandler & DataHandler::getInstance() {
	static DataHandler instance;
	return instance;
}

