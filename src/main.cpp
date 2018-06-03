#include <iostream>
#include <vector>
#include "UI/MainMenu.hpp"
#include "Game/Quiz.hpp"
#include "IO/Importer.hpp"
#include "IO/Exporter.hpp"
#include "IO/DataHandler.hpp"

using namespace std;


int main() {

	if ( Importer::loadFromFile( "../examples/import.dat", DataHandler::getInstance().mQuizzes ) ) {
		cout << "Sample data read successfully." << endl;
	} else {
		cout << "Failed to read sample data." << endl;
	}

	Exporter::exportToFile( "../examples/export.dat", DataHandler::getInstance().mQuizzes );

	MainMenu::run();


	return 0;
}

