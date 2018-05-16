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
	Question() : mId( 0 ) {}

	Question(const size_t id, const std::string & questionText) : mId( id ), mQuestionText( questionText ) {}

	virtual ~Question() {}

	virtual std::string printQuestion() { return mQuestionText; }

	virtual std::string printAnswers()=0;

	virtual std::string printCorrectAnswer()=0;

	virtual std::string printHint()=0;

	virtual std::string exportIntoFileFormat()=0;

	virtual bool evaluate()=0;

protected:
	size_t mId;
	std::string mQuestionText;
	bool isBranching = false;
};


#endif //SEMESTRAL_PROJECT_QUESTION_H
