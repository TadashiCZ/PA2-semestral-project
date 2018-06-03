//
// Created by Tadeáš Valenta on 27.5.18.
//

#ifndef SEMESTRAL_PROJECT_EXPOIMPO_H
#define SEMESTRAL_PROJECT_EXPOIMPO_H


#include "../Game/Quiz.hpp"

class DataHandler {
public:

	DataHandler();

	DataHandler(std::vector<Quiz> & quizzes);

	int IOMenu();

	bool static checkInputFilename(std::string & input);

	std::string static promptFilename();

	bool importQuizzes();

	bool exportQuizzes();

	void runIO();

	std::vector<Quiz> mQuizzes;
};


#endif //SEMESTRAL_PROJECT_EXPOIMPO_H
