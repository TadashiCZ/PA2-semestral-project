//
// Created by Tadeáš Valenta on 31.5.18.
//

#include "MultiChoiceQuestion.hpp"
#include "../../Constants.hpp"

MultiChoiceQuestion::MultiChoiceQuestion(const std::string & questionText,
                                         std::vector<std::pair<std::string, bool>> choices)
		: Question( questionText ), mChoices( choices ) {
	char c = 'a';
	mLowerCapsAnswer.clear();
	for ( std::pair<std::string, bool> choice : mChoices ) {
		if ( choice.second ) {
			mLowerCapsAnswer.push_back( c );
		}
		c++;
	}
}

const std::string MultiChoiceQuestion::printFullQuestion() {
	std::string output;
	output.append( COLOR_GREEN ).append( "Question: " ).append( COLOR_RESET ).append( mQuestionText ).append( "\n" );
	char c = 'a';
	for ( std::pair<std::string, bool> choice : mChoices ) {
		output.append( "\t" );
		output.push_back( c );
		( c == 'd' ) ? output.append( ") " ).append( choice.first ) : output.append( ") " ).append( choice.first ).append( "\n" );
		c++;
	}

	return output;
}

std::string MultiChoiceQuestion::printCorrectAnswer() {
	std::string output;
	for ( std::pair<std::string, bool> choice : mChoices ) {
		output.append( choice.first ).append( ": " ).append( BoolToStringNumber( choice.second ) ).append( "\n" );
	}
	return output;
}

std::string MultiChoiceQuestion::printHint() {
	return mHowToAnswer;
}

std::string MultiChoiceQuestion::exportIntoFileFormat() {
	std::string output;
	output.append( "Question\n" ).
			append( "MultiChoiceQuestion\n" ).
			append( mQuestionText ).append( "\n" );
	for ( std::pair<std::string, bool> choice : mChoices ) {
		output.append( choice.first ).append( "\n" ).append( BoolToStringNumber( choice.second ) ).append( "\n" );
	}
	return output;
}

bool MultiChoiceQuestion::evaluate() {
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


	return true;
}
