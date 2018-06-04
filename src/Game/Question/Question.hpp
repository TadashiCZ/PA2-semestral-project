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

class Question {
public:
	Question();

	Question(const std::string & questionText);

	virtual ~Question() {}

	const std::string printQuestion();

	virtual const std::string printFullQuestion();

	virtual std::string printCorrectAnswer()=0;

	virtual std::string printHint()=0;

	virtual std::string exportIntoFileFormat()=0;

	virtual bool evaluate()=0;

	virtual int type();

	void setBranching(bool branch);

	bool isBranching();

protected:
	size_t mId;
	std::string mQuestionText;
	bool mIsBranching = false;
};


#endif //SEMESTRAL_PROJECT_QUESTION_H
