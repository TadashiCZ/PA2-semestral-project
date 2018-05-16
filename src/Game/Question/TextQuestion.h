//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TEXTQUESTION_H
#define SEMESTRAL_PROJECT_TEXTQUESTION_H


#include "Question.h"

class TextQuestion : public Question {
public:
	TextQuestion(const size_t id, const std::string & questionText, const std::string & answer)
			: Question( id, questionText ), mAnswer( answer ) {}

	virtual std::string printQuestion() override;

	virtual std::string printAnswers() override;

	virtual std::string printCorrectAnswer() override;

	virtual std::string printHint() {
		return mHowToAnswer;
	}

	virtual std::string exportIntoFileFormat() override;

	virtual bool evaluate() override;

protected:
	std::string mAnswer;
	static constexpr std::string mHowToAnswer;

};

static const std::string TextQuestion::mHowToAnswer = "Write correct answer. No typos allowed!";


#endif //SEMESTRAL_PROJECT_TEXTQUESTION_H
