//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_PAGE_H
#define SEMESTRAL_PROJECT_PAGE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Question/Question.hpp"

class Page {
public:
	/**
	 * Empty constructor to make a placeholder
	 */
	Page();

	/**
	 * Creates page with empty branches (last page of quiz)
	 * @param questionList
	 */
	Page(std::vector<std::shared_ptr<Question>> & questionList);


	/**
	 * Creates page with branches, if should be last, give nullptr
	 * @param questionList
	 * @param branches
	 */
	Page(std::vector<std::shared_ptr<Question>> & questionList, std::vector<std::shared_ptr<Page>> & branches);

	/**
	 * copy constructor
	 * @param page
	 */
	Page(const Page & page);

	/**
	 * Starts game play of page
	 * @param 	score int to add the result score
	 * @param 	scorePossible int to add the possible score
	 * @return 	pointer to next page to play, nullptr if last page
	 */
	Page * play(int & score, int & scorePossible);

	/**
	 * Exports page into file archive format
	 * @param pageNumber page number in quiz
	 * @return string with page in file archive format
	 */
	std::string exportPageIntoFile(int pageNumber);

	std::string printQuestionList();

	std::vector<std::shared_ptr<Question>> mQuestions;
	std::vector<std::shared_ptr<Page>> mBranches;
	bool isBranching;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
