//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TEXTQUESTION_H
#define SEMESTRAL_PROJECT_TEXTQUESTION_H


#include <algorithm>
#include "Question.h"

class TextQuestion : public Question {
public:
	TextQuestion(const size_t id, const std::string & questionText, const std::string & answer)
			: Question( id, questionText ), mAnswer( answer ) {
		mLowerCapsAnswer = mAnswer;
		std::transform( mLowerCapsAnswer.begin(), mLowerCapsAnswer.end(), mLowerCapsAnswer.begin(), ::tolower );
	}

	virtual const std::string printQuestion() override {
		return mQuestionText;
	}

	virtual std::string printCorrectAnswer() override {
		return mAnswer;
	}

	virtual std::string printHint() {
		return mHowToAnswer;
	}

	virtual std::string exportIntoFileFormat() override {
		std::string output;

		output.append( "-\n" ).append( "TextQuestion\n" ).append( "Branching:" ).append( BoolToString( isBranching() ) ).append(
						"\nID:" ).append( std::to_string( mId ) )
				.append( "\n" ).append( "QuestionText:" ).append( mQuestionText ).append( "\n" ).append( "Answer:" )
				.append( mAnswer ).append( "-\n" );
		return output;
	}

	virtual bool evaluate() override {
		std::string answer;
		while ( true ) {
			std::cin >> answer;
			if ( answer.empty() ) {
				std::cout << "Not like this. Try again. " << mHowToAnswer << std::endl;
				continue;
			} else {
				break;
			}
		}
		std::transform( answer.begin(), answer.end(), answer.begin(), ::tolower );
		return answer == mLowerCapsAnswer;

	}

protected:
	std::string mAnswer;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct answer. No typos allowed!";

};


#endif //SEMESTRAL_PROJECT_TEXTQUESTION_H
