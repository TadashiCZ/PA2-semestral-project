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
	MultiChoiceQuestion(const size_t id, const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> & choices);

	virtual const std::string printQuestion() override;

	virtual std::string printCorrectAnswer() override;

	virtual std::string printHint();

	virtual std::string exportIntoFileFormat() override;

	virtual bool evaluate() override;


protected:
	std::vector<std::pair<std::string, bool>> mChoices;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct ones (ex. abd) in alphabetical order.";
};


#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
