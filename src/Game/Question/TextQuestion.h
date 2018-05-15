//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TEXTQUESTION_H
#define SEMESTRAL_PROJECT_TEXTQUESTION_H


#include "Question.h"

class TextQuestion : public Question {
public:
	TextQuestion(const size_t id, const std::string & author, const std::string & questionText, const std::string & answer);
	virtual std::string & printQuestion() override;
	virtual std::string & printAnswers() override;
	virtual std::string & printCorrectAnswer() override;
	virtual std::string & exportIntoFileFormat() override;
	virtual bool evaluate() override;

};


#endif //SEMESTRAL_PROJECT_TEXTQUESTION_H
