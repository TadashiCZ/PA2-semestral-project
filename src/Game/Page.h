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

protected:
	std::vector<Question*> mQuestions;
	std::vector<Page*> mBranches;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
