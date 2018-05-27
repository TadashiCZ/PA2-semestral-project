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
	Page(std::vector<std::shared_ptr<Question>> & questionList) : mQuestions( questionList ),
	                                                              mBranches( std::vector<std::shared_ptr<Page>>{nullptr} ) {}

	Page(std::vector<std::shared_ptr<Question>> & questionList, std::vector<std::shared_ptr<Page>> & branches)
			: mQuestions( questionList ), mBranches( branches ) {}

	Page(const Page & page) {


		mBranches.clear();
		mQuestions.clear();

		for ( auto it = page.mQuestions.begin() ; it != page.mQuestions.end() ; ++it ) {
			mQuestions.push_back( *it );
		}
		for ( auto it = page.mBranches.begin() ; it != page.mBranches.end() ; ++it ) {
			mBranches.push_back( *it );
		}
	}

	Page * play(int & score, int & scorePossible) {
		for ( auto it = mQuestions.begin() ; it != mQuestions.end() ; ++it ) {
			std::cout << ( **it ).printQuestion() << std::endl;
			std::cout << ( **it ).printHint() << std::endl;
			if ( ( **it ).evaluate() ) {
				score++;
				scorePossible++;
				std::cout << "Correct!" << std::endl << std::endl;
				if ( ( **it ).isBranching() ) {
					std::cout << "Current score: " << score << "/" << scorePossible << std::endl;
					std::cout << "End of page. Press Enter to continue..." << std::endl;
					std::cin.get();
					std::cin.get();
					return mBranches[0].get();
				}
			} else {
				scorePossible++;
				std::cout << "Wrong, good luck with the next one." << std::endl << std::endl;
				if ( ( **it ).isBranching() ) {
					std::cout << "Current score: " << score << "/" << scorePossible << std::endl;
					std::cout << "End of page. Press Enter to continue..." << std::endl;
					std::cin.get();
					std::cin.get();
					return mBranches[1].get();
				}
			}
		}


		std::cout << "Current score: " << score << "/" << scorePossible << std::endl;
		std::cout << "End of page. Press Enter to continue..." << std::endl;
		std::cin.get();
		std::cin.get();
		return mBranches[0].get(); // return branch which one should go to
	}

	std::string exportPage(){
		std::string output;
		std::stringstream ss;

		ss << mQuestions.size();
		output.append("-\nPage\nQuestionCount:").append( ss.str() );
		ss.clear();
		ss.str("");
		ss << mBranches.size();
		output.append(";BranchCount:").append(ss.str()).append("\n");
		for ( std::shared_ptr<Question> quest : mQuestions ){
			output.append(quest->exportIntoFileFormat());
		}
		output.append("-\n");
		return output;
	}

protected:
	std::vector<std::shared_ptr<Question>> mQuestions;
	std::vector<std::shared_ptr<Page>> mBranches;
};


#endif //SEMESTRAL_PROJECT_PAGE_H
