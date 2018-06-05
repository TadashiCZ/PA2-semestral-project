#include <iostream>
#include <vector>
#include "UI/MainMenuScreen.hpp"
#include "Game/Quiz.hpp"
#include "Database/Importer.hpp"
#include "Database/Exporter.hpp"
#include "Database/DataHandler.hpp"
#include "Constants.hpp"


using namespace std;


void loadExampleData();


int main() {

	loadExampleData();
	MainMenuScreen(cout).run();

	return 0;
}

void loadExampleData() {
	if ( Importer::loadFromFile( DEFAULT_DATA_FILE, DataHandler::getInstance().mQuizzes ) ) {
		cout << "Sample data read successfully." << endl;
	} else {
		cout << "Failed to read sample data." << endl;
	}
}

