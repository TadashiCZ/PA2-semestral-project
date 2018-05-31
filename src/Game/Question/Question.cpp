//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "Question.hpp"

Question::Question() : mId( 0 ) {}

Question::Question(const size_t id, const std::string & questionText) : mId( id ), mQuestionText( questionText ) {}

const std::string Question::printQuestion() { return mQuestionText; }

void Question::setBranching(bool branch) { mIsBranching = branch; }

bool Question::isBranching() { return mIsBranching; }
