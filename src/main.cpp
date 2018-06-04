#include <iostream>
#include <vector>
#include "UI/MainMenuScreen.hpp"
#include "Game/Quiz.hpp"
#include "Database/Importer.hpp"
#include "Database/Exporter.hpp"
#include "Database/DataHandler.hpp"

using namespace std;


int main() {

	if ( Importer::loadFromFile( "../examples/import.dat", DataHandler::getInstance().mQuizzes ) ) {
		cout << "Sample data read successfully." << endl;
	} else {
		cout << "Failed to read sample data." << endl;
	}

	Exporter::exportToFile( "../examples/export.dat", DataHandler::getInstance().mQuizzes );

	MainMenuScreen(cout).run();


	return 0;
}

