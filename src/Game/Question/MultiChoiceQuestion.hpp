//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
#define SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "Question.hpp"
/**
 * Question with multiple choices and multiple correct answers.
 */
class MultiChoiceQuestion : public Question {
public:
	/**
	 * Creates multiple choice question
	 * @param questionText non empty string
	 * @param choices always 4 pairs
	 */
	MultiChoiceQuestion(const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> choices);

	/**
	 * CLI formatted list of correct answers (by true/false and color)
	 * @return colorized string
	 */
	virtual std::string printCorrectAnswer() override;

	/**
	 * CLI formatted string with hint how to answer the question
	 * @return string with hint
	 */
	virtual std::string printHint();

	/**
	 * Creates string with question formatted into file format
	 * @return question in file format
	 */
	virtual std::string exportIntoFileFormat() override;

	/**
	 * Prompts the answer and checks if its correct
	 * @return true on correct, false on not
	 */
	virtual bool evaluate() override;

	/**
	 * CLI formatted question with colors and possible answers
	 * @return
	 */
	virtual const std::string printFullQuestion() override;

	/**
	 * Returns id of type of the question as defined in Constants
	 * @return
	 */
	virtual int type() override;

protected:
	/**
	 * choices and their correctness
	 */
	std::vector<std::pair<std::string, bool>> mChoices;

	/**
	 * Answer in lowercaps (ex. abd)
	 */
	std::string mLowerCapsAnswer;
	/**
	 * Hint for user who doesn't know how to answer
	 */
	const std::string mHowToAnswer = "Write correct ones (ex. abd) in alphabetical order.";
};


#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
