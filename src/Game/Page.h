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
	Page(std::vector<Question *> & questionList) : mQuestions( questionList ), mBranches( std::vector<Page *>{nullptr} ) {}

	Page(std::vector<Question *> & questionList, std::vector<Page *> & branches)
			: mQuestions( questionList ), mBranches( branches ) {}

	Page(const Page & page) {
		for ( Question * question : mQuestions ) {
			delete question;
		}

		for ( Page * branch : mBranches ) {
			delete branch;
		}
		mBranches.clear();
		mQuestions.clear();

		for ( Question * question : page.mQuestions ) {
			mQuestions.push_back( question );
		}
		for ( Page * branch : page.mBranches ) {
			mBranches.push_back( branch );
		}
	}

	Page * play(int & score, int & scorePossible) {


		for ( Question * question : mQuestions ) {
			std::cout << question->printQuestion() << std::endl;
			std::cout << question->printHint() << std::endl;
			std::cout << question->printAnswers() << std::endl;
			if (question->evaluate()){
				score++;
				scorePossible++;
				std::cout << "Correct!" << std::endl;
				if ( question->isBranching() ){
					return mBranches[0];
				}
			} else {
				scorePossible++;
				std::cout << "Wrong, good luck with the next one." << std::endl;
				if ( question->isBranching() ){
					return mBranches[1];
				}
			}
		}

		std::cout << "Current score: " << score << "/" << scorePossible << std::endl;
		std::cout << "End of page. Press Enter to continue..." << std::endl;
		std::cin.get();
		std::cin.get();

		return mBranches[0]; // return branch which one should go to
	}

protected:
	std::vector<Question *> mQuestions;
	std::vector<Page *> mBranches;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
