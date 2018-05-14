//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUIZ_H
#define SEMESTRAL_PROJECT_QUIZ_H

#include "Page.h"

class Quiz {
public:
	void printInList();
	void print();


protected:
	std::vector<Page*> mPages;



};


#endif //SEMESTRAL_PROJECT_QUIZ_H
