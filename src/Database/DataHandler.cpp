//
// Created by Tadeáš Valenta on 28.5.18.
//

#include "DataHandler.hpp"
#include "Importer.hpp"
#include "Exporter.hpp"
#include "../Constants.hpp"

using namespace std;

int DataHandler::IOMenu() {
	cout << COLOR_YELLOW << "Do you want to import or export quizzes? Write it. (Or write \"exit\" if you want to go back.)"
	     << COLOR_RESET << endl;
	while ( true ) {
		string dummy;
		cin.clear();
		cin >> dummy;
		if ( dummy == "exit" ) {
			return -1;
		} else if ( dummy == "import" ) {
			return 1;
		} else if ( dummy == "export" ) {
			return 2;
		} else {
			cout << "Not like this. Write \"import\", \"export\" or \"exit\"." << endl;
		}
	}
}

bool DataHandler::saveQuizData() {
	Exporter::exportToFile( DEFAULT_DATA_FILE, DataHandler::getInstance().mQuizzes );
	return true;
}

bool DataHandler::exportQuizzes() {
	string outputFileName = DataHandler::promptFilename();
	vector<Quiz> forExport;
	showQuizList();
	cout << COLOR_YELLOW
	     << "Which quizzes you want to export? Write one number and press Enter, then another one etc. Write \"done\" when you're done and \"all\" if you want to export all."
	     << COLOR_RESET << endl;
	int output;
	while ( true ) {
		output = addQuizForExportInteractive( forExport );
		if ( output == 0 ) {
			if ( forExport.size() > 0 ) {
				cout << COLOR_YELLOW << "Exporting selected into file " << outputFileName << "." << COLOR_RESET << endl;
				if ( !Exporter::exportToFile( outputFileName, forExport ) ) {
					cout << COLOR_RED << "Export failed." << COLOR_RESET << endl;
					return false;
				}
			} else {
				cout << COLOR_RED << "No quizzes selected, therefore no quizzes exported." << COLOR_RESET << endl;
			}
			break;
		} else if ( output == 1 ) {
			continue;
		} else if ( output == 2 ) {
			cout << COLOR_YELLOW << "Exporting all into file " << outputFileName << "." << COLOR_RESET << endl;
			if ( !Exporter::exportToFile( outputFileName, DataHandler::getInstance().mQuizzes ) ) {
				cout << COLOR_RED << "Export failed." << COLOR_RESET << endl;
				return false;
			}
			return true;
		}
	}


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

string DataHandler::promptFilename() {
	cout << COLOR_YELLOW << "Write relative filepath to file with quizzes." << COLOR_RESET << endl;
	while ( true ) {
		string dummy = "";
		char input[250];
		cin.ignore();
		while ( dummy.empty() ) {
			cin.getline( input, 249 );
			dummy = input;
		}
		return dummy;
	}
}

bool DataHandler::importQuizzes() {
	string inputFileName = DataHandler::promptFilename();
	return Importer::loadFromFile( inputFileName, mQuizzes );
}

DataHandler & DataHandler::getInstance() {
	static DataHandler instance;
	return instance;
}

int DataHandler::addQuizForExportInteractive(std::vector<Quiz> & forExport) {
	cout << COLOR_YELLOW << "Number, done or all." << COLOR_RESET << endl;
	string dummy;
	unsigned int number;
	while ( true ) {
		cin >> dummy;
		if ( dummy == "all" ) {
			return 2;
		} else if ( dummy == "done" ) {
			return 0;
		} else if ( isdigit( dummy[0] ) ) {
			number = atoi( dummy.c_str() );
			if ( number > 0 && number <= DataHandler::getInstance().mQuizzes.size() ) {
				forExport.push_back( DataHandler::getInstance().mQuizzes[number - 1] );
				return 1;
			}
		}
	}
}

void DataHandler::showQuizList() {
	cout << endl << COLOR_BLUE << "Quiz list:" << COLOR_RESET << endl;
	for ( size_t i = 0 ; i < DataHandler::getInstance().mQuizzes.size() ; ++i ) {
		cout << COLOR_BLUE << i + 1 << ") " << COLOR_RESET << DataHandler::getInstance().mQuizzes[i].printQuizListInfo()
		     << endl;
	}
}

