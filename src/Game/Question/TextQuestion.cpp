//
// Created by Tadeáš Valenta on 28.5.18.
//


#include "TextQuestion.h"


TextQuestion::TextQuestion(const size_t id, const std::string & questionText, const std::string & answer)
		: Question( id, questionText ), mAnswer( answer ) {
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

	output.append( "-\n" ).append( "TextQuestion\n" ).append( "Branching:" ).append( BoolToString( isBranching() ) ).append(
					"\nID:" ).append( std::to_string( mId ) )
			.append( "\n" ).append( "QuestionText:" ).append( mQuestionText ).append( "\n" ).append( "Answer:" )
			.append( mAnswer ).append( "\n-\n" );
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

