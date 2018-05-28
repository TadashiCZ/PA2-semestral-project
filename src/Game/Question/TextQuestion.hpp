//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TEXTQUESTION_H
#define SEMESTRAL_PROJECT_TEXTQUESTION_H


#include <algorithm>
#include "Question.hpp"

class TextQuestion : public Question {
public:
	TextQuestion(size_t id, const std::string & questionText, const std::string & answer);

	virtual const std::string printQuestion();

	virtual std::string printCorrectAnswer();

	virtual std::string printHint();

	virtual std::string exportIntoFileFormat();

	virtual bool evaluate();

protected:
	std::string mAnswer;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct answer. No typos allowed!";

};

#endif //SEMESTRAL_PROJECT_TEXTQUESTION_H
