//
// Created by Tadeáš Valenta on 28.5.18.
//


#include "TextQuestion.hpp"
#include "../../Constants.hpp"

using namespace std;

TextQuestion::TextQuestion(const string & questionText, const string & answer)
		: Question( questionText ), mAnswer( answer ) {
	mLowerCapsAnswer = mAnswer;
	transform( mLowerCapsAnswer.begin(), mLowerCapsAnswer.end(), mLowerCapsAnswer.begin(), ::tolower );
}

const string TextQuestion::printFullQuestion() {
	string output;
	output.append(COLOR_GREEN).append("Question: ").append(COLOR_RESET).append(mQuestionText);
	return output;
}

string TextQuestion::printCorrectAnswer() {
	return mAnswer;
}

string TextQuestion::printHint() {
	return mHowToAnswer;
}

string TextQuestion::exportIntoFileFormat() {
	string output;
	output.append( "Question\n" ).append( "TextQuestion\n" ).
			append( mQuestionText ).append( "\n" ).append( mAnswer ).append( "\n" );
	return output;
}

bool TextQuestion::evaluate() {
	string answer;
	while ( true ) {
		cin >> answer;
		if ( answer.empty() ) {
			cout << "Not like this. Try again. " << mHowToAnswer << endl;
			continue;
		} else {
			break;
		}
	}
	transform( answer.begin(), answer.end(), answer.begin(), ::tolower );
	return answer == mLowerCapsAnswer;

}

int TextQuestion::type() {
	return TEXT_QUESTION;
}

