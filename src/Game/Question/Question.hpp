//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUESTION_H
#define SEMESTRAL_PROJECT_QUESTION_H

#include <iostream>
#include <cstddef>

inline const char * const BoolToStringNumber(bool b) {
	return b ? "1" : "0";
}
/**
 * Abstract class used as a base for all question types
 */
class Question {
public:
	/**
	 * Empty constructor (question text set to "")
	 */
	Question()=default;

	/**
	 * Constructor with given question text
	 * @param questionText
	 */
	Question(const std::string & questionText);

	virtual ~Question() {}

	/**
	 * Returns string with only question text
	 * @return
	 */
	const std::string printQuestion();

	/**
	 * Returns colorized string formatted for CLI
	 * @return
	 */
	virtual const std::string printFullQuestion();

	/**
	 * CLI formatted list of correct answers (by true/false and color)
	 * @return colorized string
	 */
	virtual std::string printCorrectAnswer()=0;

	/**
	 * CLI formatted string with hint how to answer the question
	 * @return string with hint
	 */
	virtual std::string printHint()=0;

	/**
	 * Creates string with question formatted into file format
	 * @return question in file format
	 */
	virtual std::string exportIntoFileFormat()=0;

	/**
	 * Prompts the answer and checks if its correct
	 * @return true on correct, false on not
	 */
	virtual bool evaluate()=0;

	/**
	 * Returns id of type of the question as defined in Constants
	 * @return
	 */
	virtual int type();

protected:
	/**
	 * text to be asked
	 */
	std::string mQuestionText;
};


#endif //SEMESTRAL_PROJECT_QUESTION_H
