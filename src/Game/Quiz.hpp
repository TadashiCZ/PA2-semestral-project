//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include <sstream>
#include "Page.hpp"
/**
 * Holds all data for quiz
 */
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
	 * Creates string with quiz info to be put into list of quizzes
	 * @return	string with the quiz info
	 */
	std::string printQuizListInfo();

	/**
	 * Creates string with quiz in file export format
	 * @return string with the quiz in file export format
	 */
	std::string exportQuizIntoFile();

	/**
	 * Creates string with tree relationships of this quiz
	 * @return realationships separated by newline
	 */
	std::string printTree();

	/**
	 * Creates string with list of pages (and their questions) in this quiz
	 * @return list of pages with appropriate list of questions in CLI format
	 */
	std::string printPageList();

	bool operator==(Quiz & quiz);

	std::string mName;
	std::string mAuthor;
	std::vector<std::shared_ptr<Page>> mPages;


};


#endif //SEMESTRAL_PROJECT_QUIZ_H
