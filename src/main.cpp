#include <iostream>
#include <fstream>
#include <memory>
#include "UI/MainMenu.hpp"
#include "Game/Quiz.hpp"
#include "Game/Game.hpp"
#include "IO/ExpoImpo.hpp"
#include "IO/Importer.hpp"
#include "IO/Exporter.hpp"

using namespace std;

int main() {
	vector<Quiz> quizzes;
	if ( Importer::loadFromFile( "../examples/import.dat", quizzes ) ) {
		cout << "Sample data read successfully." << endl;
	} else {
		cout << "Failed to read sample data." << endl;
	}
	Exporter::exportToFile( "../examples/export.dat", quizzes );

	MainMenu::welcomeUser();
	bool looping = true;
	bool showMenu = false;
	MainMenu::show();
	while ( looping ) {
		if (showMenu) MainMenu::show();
		switch ( MainMenu::promptMainMenu() ) {
			case 1: // Play
				showMenu = true;
				Game( quizzes ).play();
				break;
			case 2: // Add
				showMenu = true;
				//startAdd();
				break;
			case 3: //Edit
				showMenu = true;
				//startEdit();
				break;
			case 4: //Export
				showMenu = true;
				ExpoImpo( quizzes ).run();
				break;
			case 5: //End
				// saveIntoFile();
				return 0;
			default: showMenu = false;
				cout << "Wrong choice, try again." << endl;
		}

	}

	return -1;
}

