//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_PAGE_H
#define SEMESTRAL_PROJECT_PAGE_H

#include <iostream>
#include <vector>
#include "Question/Question.h"

class Page {
public:
	Page(const Page & page){
		for (Question * question : mQuestions){
			delete question;
		}

		for (Page * branch : mBranches){
			delete branch;
		}
		mBranches.clear();
		mQuestions.clear();

		for (Question * question : page.mQuestions){
			mQuestions.push_back(question);
		}
		for (Page * branch : page.mBranches){
			mBranches.push_back(branch);
		}
	}


protected:
	std::vector<Question*> mQuestions;
	std::vector<Page*> mBranches;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
