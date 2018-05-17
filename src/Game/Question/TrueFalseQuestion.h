//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
#define SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H


#include <algorithm>
#include "Question.h"

class TrueFalseQuestion : public Question {
public:
	TrueFalseQuestion(const size_t id, const std::string & questionText, bool answer)
			: Question( id, questionText ), mAnswer( answer ) {}

	virtual std::string printQuestion() override {
		return mQuestionText;
	}

	virtual std::string printAnswers() override {
		std::string answer = "True or false";
		return answer;
	}

	virtual std::string printCorrectAnswer() override {
		std::string trueStr = "True";
		std::string falseStr = "False";
		return ( mAnswer ) ? trueStr : falseStr;
	}

	virtual std::string printHint() {
		return mHowToAnswer;
	}

	virtual std::string exportIntoFileFormat() {
		std::string output;

	output.append( "-\n" ).append( "TrueFalseQuestion\n" ).append( "Branching:" ).append( BoolToString(isBranching()) ).append(
						"\nID:" ).append( std::to_string( mId ) )
				.append( "\n" ).append( "QuestionText:" ).append( mQuestionText ).append( "\n" ).append( "Answer:" );
		( mAnswer ) ? output.append( "True\n" ) : output.append( "False\n" );
		output.append( "-\n" );
		return output;

	}

	virtual bool evaluate() override {
		std::string answer;
		bool boolAnswer;
		while ( true ) {
			std::cin >> answer;
			std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
			if (answer == "true" || answer == "false" ){
				break;
			} else {
				std::cout << "Not like this. Try again. " << mHowToAnswer << std::endl;
				continue;
			}
		}

		boolAnswer = (answer == "true") ? true : false;
		return boolAnswer == mAnswer;
	}

protected:
	bool mAnswer;
	const std::string mHowToAnswer = "Write \"True\" or \"False\".";

};

#endif //SEMESTRAL_PROJECT_TRUEFALSEQUESTION_H
