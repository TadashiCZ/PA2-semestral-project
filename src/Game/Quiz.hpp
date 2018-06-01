//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include <sstream>
#include "Page.hpp"

class Quiz {
public:

	/**
	 * Basic constructor
	 * @param name default given is empty
	 */
	Quiz(std::string name = "");

	Quiz(const std::string & quizName, const std::string & authorName, std::vector<std::shared_ptr<Page>> & pages);

	Quiz(const Quiz & quiz);

	bool play(int & score, int & scorePossible);

	std::string printQuizListInfo();

	std::string exportQuizIntoFile();

	std::string & print();


	std::string mName;
	std::string mAuthor;
	std::vector<std::shared_ptr<Page>> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H
