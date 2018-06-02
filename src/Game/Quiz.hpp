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

	/**
	 * Complete constructor
	 * @param quizName name of quiz
	 * @param authorName name of author
	 * @param pages vector of pages to include
	 */
	Quiz(const std::string & quizName, const std::string & authorName, std::vector<std::shared_ptr<Page>> & pages);

	/**
	 * Copy constructor
	 * @param 	quiz
	 */
	Quiz(const Quiz & quiz);

	/**
	 * Interacts with the user, plays the quiz
	 * @param 	score int to place the result score
	 * @param 	scorePossible int to place the possible score
	 * @return 	true if player successful, false otherwise
	 */
	bool play(int & score, int & scorePossible);

	/**
	 * Creates string with quiz info to be put into list of quizzes
	 * @return	string with the quiz info
	 */
	std::string printQuizListInfo();

	/**
	 * Creates string with quiz in file export format
	 * @return string with the quiz in file export format
	 */
	std::string exportQuizIntoFile();

	std::string mName;
	std::string mAuthor;
	std::vector<std::shared_ptr<Page>> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H
