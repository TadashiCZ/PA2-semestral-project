//
// Created by Tadeáš Valenta on 27.5.18.
//

#ifndef SEMESTRAL_PROJECT_EXPOIMPO_H
#define SEMESTRAL_PROJECT_EXPOIMPO_H


class ExpoImpo {
public:
	ExpoImpo(std::vector<Quiz> & quizzes) : mQuizzes( quizzes ) {}

	int importOrExport() {
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

	bool checkInputFilename(std::string & input) {


		return true;
	}

	std::string promptFilename() {
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

	bool importQuizzes() {
		//todo import from file
		std::string inputFileName = promptFilename();
		std::ofstream ofs( inputFileName, std::ofstream::out );
		if ( ofs.fail() ) {
			std::cout << "Failed to open file for writing." << std::endl;
			return false;
		}
		return true;
	}

	bool exportQuizzes() {

		return true;
	}

	void run() {
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

private:
	std::vector<Quiz> mQuizzes;
};


#endif //SEMESTRAL_PROJECT_EXPOIMPO_H
