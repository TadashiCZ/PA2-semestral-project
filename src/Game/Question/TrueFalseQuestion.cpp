//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "TrueFalseQuestion.hpp"
#include "../../Constants.hpp"

using namespace std;

TrueFalseQuestion::TrueFalseQuestion(const string & questionText, bool answer)
		: Question( questionText ), mAnswer( answer ) {}

const string TrueFalseQuestion::printFullQuestion() {
	string output;
	output.append(COLOR_GREEN).append("Question: ").append(COLOR_RESET).append(mQuestionText);
	return output;
}

string TrueFalseQuestion::printCorrectAnswer() {
	string trueStr = "True";
	string falseStr = "False";
	return ( mAnswer ) ? trueStr : falseStr;
}

string TrueFalseQuestion::exportIntoFileFormat() {
	string output;

	output.append( "Question\nTrueFalseQuestion\n" ).
			append( mQuestionText ).append( "\n" );
	( mAnswer ) ? output.append( "1\n" ) : output.append( "0\n" );
	return output;
}

string TrueFalseQuestion::printHint() {
	return mHowToAnswer;
}

bool TrueFalseQuestion::evaluate() {
	string answer;
	bool boolAnswer;
	while ( true ) {
		cin >> answer;
		transform( answer.begin(), answer.end(), answer.begin(), ::tolower );
		if ( answer == "true" || answer == "false" ) {
			break;
		} else {
			cout << "Not like this. Try again. " << mHowToAnswer << endl;
			continue;
		}
	}

	boolAnswer = ( answer == "true" ) ? true : false;
	return boolAnswer == mAnswer;
}

int TrueFalseQuestion::type() {
	return TRUE_FALSE_QUESTION;
}
