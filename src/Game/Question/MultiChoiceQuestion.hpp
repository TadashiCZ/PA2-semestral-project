//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
#define SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "Question.hpp"

class MultiChoiceQuestion : public Question {
public:
	MultiChoiceQuestion(const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> choices);

	virtual std::string printCorrectAnswer() override;

	virtual std::string printHint();

	virtual std::string exportIntoFileFormat() override;

	virtual bool evaluate() override;
	const std::string printFullQuestion() override;

	virtual int type() override;

protected:
	std::vector<std::pair<std::string, bool>> mChoices;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct ones (ex. abd) in alphabetical order.";
};


#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
