//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "Question.hpp"

Question::Question() : mId( 0 ) {}

Question::Question(const std::string & questionText) : mQuestionText( questionText ) {}

const std::string Question::printQuestion() { return mQuestionText; }

void Question::setBranching(bool branch) { mIsBranching = branch; }

bool Question::isBranching() { return mIsBranching; }

const std::string Question::printFullQuestion() {
	return mQuestionText;
}
