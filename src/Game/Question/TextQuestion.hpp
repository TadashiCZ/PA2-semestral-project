//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TEXTQUESTION_H
#define SEMESTRAL_PROJECT_TEXTQUESTION_H


#include <algorithm>
#include "Question.hpp"

/**
 * Question with text answer.
 */
class TextQuestion : public Question {
public:
	/**
	 * Constructor for abstract class
	 * @param id
	 * @param questionText
	 * @param answer
	 */
	TextQuestion(const std::string & questionText, const std::string & answer);

	/**
	 * CLI formatted list of correct answers (by true/false and color)
	 * @return colorized string
	 */
	virtual std::string printCorrectAnswer();

	virtual std::string printHint();

	virtual std::string exportIntoFileFormat();

	virtual bool evaluate();

	virtual const std::string printFullQuestion() override;

	virtual int type() override;

protected:
	std::string mAnswer;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct answer. No typos allowed!";

};

#endif //SEMESTRAL_PROJECT_TEXTQUESTION_H
