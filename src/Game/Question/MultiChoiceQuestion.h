//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
#define SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H


#include <iostream>
#include <vector>
#include "Question.h"

class MultiChoiceQuestion : public Question {
	MultiChoiceQuestion(const size_t id, const std::string & author, const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> choices);
	virtual std::string & printQuestion() override;
	virtual std::string & printAnswers() override;
	virtual std::string & printCorrectAnswer() override;
	virtual std::string & exportIntoFileFormat();
	virtual bool evaluate() override;
};


#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
