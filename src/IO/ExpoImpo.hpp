//
// Created by Tadeáš Valenta on 27.5.18.
//

#ifndef SEMESTRAL_PROJECT_EXPOIMPO_H
#define SEMESTRAL_PROJECT_EXPOIMPO_H


#include "../Game/Quiz.hpp"

class ExpoImpo {
public:
	ExpoImpo(std::vector<Quiz> & quizzes);

	int importOrExport();

	bool static checkInputFilename(std::string & input);

	std::string static promptFilename();

	bool importQuizzes();

	bool exportQuizzes();

	void run();

private:
	std::vector<Quiz> mQuizzes;
};


#endif //SEMESTRAL_PROJECT_EXPOIMPO_H
