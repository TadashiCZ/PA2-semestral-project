//
// Created by Tadeáš Valenta on 27.5.18.
//

#ifndef SEMESTRAL_PROJECT_EXPOIMPO_H
#define SEMESTRAL_PROJECT_EXPOIMPO_H


#include "../Game/Quiz.hpp"

class DataHandler {
public:
	std::vector<Quiz> mQuizzes;

	static DataHandler & getInstance();

	int IOMenu();

	std::string static promptFilename();

	bool importQuizzes();

	bool exportQuizzes();

	void runIO();

	DataHandler(DataHandler const &) = delete;
	void operator=(DataHandler const &) = delete;


private:
	DataHandler() {}

};


#endif //SEMESTRAL_PROJECT_EXPOIMPO_H
