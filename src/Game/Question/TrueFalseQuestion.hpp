//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
#define SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H


#include <algorithm>
#include "Question.hpp"

class TrueFalseQuestion : public Question {
public:
	TrueFalseQuestion(const std::string & questionText, bool answer);

	virtual const std::string printFullQuestion();

	virtual std::string printCorrectAnswer();

	virtual std::string printHint();

	virtual std::string exportIntoFileFormat();

	virtual bool evaluate();

protected:
	bool mAnswer;
	const std::string mHowToAnswer = "Write \"True\" or \"False\".";

};

#endif //SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
