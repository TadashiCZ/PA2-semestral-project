//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUESTION_H
#define SEMESTRAL_PROJECT_QUESTION_H

#include <iostream>
#include <cstddef>

inline const char * const BoolToString(bool b) {
	return b ? "true" : "false";
}

class Question {
public:
	Question();

	Question(const size_t id, const std::string & questionText);

	virtual ~Question() {}

	virtual const std::string printQuestion();

	virtual std::string printCorrectAnswer()=0;

	virtual std::string printHint()=0;

	virtual std::string exportIntoFileFormat()=0;

	virtual bool evaluate()=0;

	void setBranching(bool branch);

	bool isBranching();

protected:
	size_t mId;
	std::string mQuestionText;
	bool mIsBranching = false;
};


#endif //SEMESTRAL_PROJECT_QUESTION_H
