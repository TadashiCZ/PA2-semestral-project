//
// Created by Tadeáš Valenta on 15.5.18.
//

#ifndef SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
#define SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "Question.hpp"

class MultiChoiceQuestion : public Question {
public:
	MultiChoiceQuestion(const size_t id, const std::string & questionText,
	                    std::vector<std::pair<std::string, bool>> & choices)
			: Question( id, questionText ), mChoices( choices ) {
		char c = 'a';
		mLowerCapsAnswer.clear();
		for ( std::pair<std::string, bool> choice : mChoices ) {
			if ( choice.second ) {
				mLowerCapsAnswer.push_back( c );
			}
			c++;
		}
	}

	virtual const std::string printQuestion() override {
		std::string output;
		output.append( mQuestionText ).append( "\n" );
		char c = 'a';
		for ( std::pair<std::string, bool> choice : mChoices ) {
			output.push_back( c );
			output.append( ") " ).append( choice.first ).append( "; " );
			c++;
		}
		output.append( "\n" );

		return output;
	}

	virtual std::string printCorrectAnswer() override {
		std::string output;
		for ( std::pair<std::string, bool> choice : mChoices ) {
			output.append( choice.first ).append( ": " ).append( BoolToString( choice.second ) ).append( "\n" );
		}
		return output;
	}

	virtual std::string printHint() {
		return mHowToAnswer;
	}

	virtual std::string exportIntoFileFormat() override {
		std::string output;
		output.append( "-\n" ).append( "MultiChoiceQuestion\n" ).append( "Branching:" ).append(
						BoolToString( isBranching() ) ).append(
						"\nID:" ).append( std::to_string( mId ) )
				.append( "\n" ).append( "QuestionText:" ).append( mQuestionText ).append( "\n" ).append( "Answer:" );
		for ( std::pair<std::string, bool> choice : mChoices ) {
			output.append( choice.first ).append( "::" ).append( BoolToString( choice.second ) ).append( ";" );
		}
		output.append( "\n-\n" );
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


		return true;
	}


protected:
	std::vector<std::pair<std::string, bool>> mChoices;
	std::string mLowerCapsAnswer;
	const std::string mHowToAnswer = "Write correct ones (ex. abd) in alphabetical order.";
};


#endif //SEMESTRAL_PROJECT_MULTICHOICEQUESTION_H
