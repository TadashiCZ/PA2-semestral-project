//
// Created by Tadeáš Valenta on 14.5.18.
//

#ifndef SEMESTRAL_PROJECT_QUESTION_H
#define SEMESTRAL_PROJECT_QUESTION_H

#include <iostream>
#include <cstddef>

class Question {
public:
	Question();
	virtual ~Question(){}
	Question(size_t id, std::string author, std::string questionText);
	virtual std::string& printQuestion();
	virtual std::string& printAnswers();
	virtual std::string& printCorrectAnswer();
	virtual std::string& exportIntoFileFormat();
	virtual bool evaluate();

protected:
	size_t mId;
	std::string mAuthor;
	std::string mQuestionText;
};


#endif //SEMESTRAL_PROJECT_QUESTION_H
