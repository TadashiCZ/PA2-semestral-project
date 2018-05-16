//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
#define SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H


#include <iostream>
#include <vector>
#include "Question.h"

class MultiChoiceQuestion : public Question {
public:
	MultiChoiceQuestion(const size_t id, const std::string & author, const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> choices);
	virtual std::string printQuestion() override;
	virtual std::string printAnswers() override;
	virtual std::string printCorrectAnswer() override;
	virtual std::string printHint() {
		return mHowToAnswer;
	}
	virtual std::string exportIntoFileFormat() override;
	virtual bool evaluate() override;


protected:
	std::vector<std::pair<std::string, bool>> mChoices;
	static constexpr std::string mHowToAnswer;
};
static constexpr std::string MultiChoiceQuestion::mHowToAnswer = "Choose a, b, c or d.";

#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
