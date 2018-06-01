//
// Created by Tadeáš Valenta on 28.5.18.
//


#include "TextQuestion.hpp"


TextQuestion::TextQuestion(const std::string & questionText, const std::string & answer)
		: Question( questionText ), mAnswer( answer ) {
	mLowerCapsAnswer = mAnswer;
	std::transform( mLowerCapsAnswer.begin(), mLowerCapsAnswer.end(), mLowerCapsAnswer.begin(), ::tolower );
}

const std::string TextQuestion::printQuestion() {
	return mQuestionText;
}

std::string TextQuestion::printCorrectAnswer() {
	return mAnswer;
}

std::string TextQuestion::printHint() {
	return mHowToAnswer;
}

std::string TextQuestion::exportIntoFileFormat() {
	std::string output;
	output.append( "Question\n" ).append( "TextQuestion\n" ).
			append( mQuestionText ).append( "\n" ).append( mAnswer ).append( "\n" );
	return output;
}

bool TextQuestion::evaluate() {
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

