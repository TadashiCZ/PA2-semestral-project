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
	Page();

	Page(std::vector<std::shared_ptr<Question>> & questionList);

	Page(std::vector<std::shared_ptr<Question>> & questionList, std::vector<std::shared_ptr<Page>> & branches);

	Page(const Page & page);

	Page * play(int & score, int & scorePossible);

	std::string exportPageIntoFile(int pageNumber);

	std::vector<std::shared_ptr<Question>> mQuestions;
	std::vector<std::shared_ptr<Page>> mBranches;
	bool isBranching;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
