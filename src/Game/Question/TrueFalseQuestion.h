//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
#define SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H


#include "Question.h"

class TrueFalseQuestion : public Question {
public:
	TrueFalseQuestion(size_t id, std::string author, std::string questionText, bool answer);
	virtual std::string & printQuestion() override;
	virtual std::string & printAnswers() override;
	virtual std::string & printCorrectAnswer() override;
	virtual std::string & exportIntoFileFormat();
	virtual bool evaluate() override;

protected:
	bool mAnswer;
	static const std::string mHowToAnswer = "Write \"T\" or \"F\".";


};


#endif //SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
