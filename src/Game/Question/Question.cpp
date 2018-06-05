//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "Question.hpp"
#include "../../Constants.hpp"

using namespace std;

Question::Question(const string & questionText) : mQuestionText( questionText ) {}

const string Question::printQuestion() { return mQuestionText; }

const string Question::printFullQuestion() {
	string output;
	output.append(COLOR_GREEN).append("Question: ").append(mQuestionText);
	return output;
}

int Question::type() {
	return ABSTRACT_QUESTION;
}
