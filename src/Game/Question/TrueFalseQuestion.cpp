//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "TrueFalseQuestion.hpp"


TrueFalseQuestion::TrueFalseQuestion(const std::string & questionText, bool answer)
		: Question( questionText ), mAnswer( answer ) {}

const std::string TrueFalseQuestion::printQuestion() {

	return mQuestionText;
}

std::string TrueFalseQuestion::printCorrectAnswer() {
	std::string trueStr = "True";
	std::string falseStr = "False";
	return ( mAnswer ) ? trueStr : falseStr;
}

std::string TrueFalseQuestion::exportIntoFileFormat() {
	std::string output;

	output.append( "Question\nTrueFalseQuestion\n" ).
			append( mQuestionText ).append( "\n" );
	( mAnswer ) ? output.append( "1\n" ) : output.append( "0\n" );
	return output;
}

std::string TrueFalseQuestion::printHint() {
	return mHowToAnswer;
}

bool TrueFalseQuestion::evaluate() {
	std::string answer;
	bool boolAnswer;
	while ( true ) {
		std::cin >> answer;
		std::transform( answer.begin(), answer.end(), answer.begin(), ::tolower );
		if ( answer == "true" || answer == "false" ) {
			break;
		} else {
			std::cout << "Not like this. Try again. " << mHowToAnswer << std::endl;
			continue;
		}
	}

	boolAnswer = ( answer == "true" ) ? true : false;
	return boolAnswer == mAnswer;
}
