//
// Created by Tadeáš Valenta on 28.5.18.
//

#include <fstream>
#include <cstring>
#include "Importer.hpp"
#include "../Game/Question/MultiChoiceQuestion.hpp"
#include "../Game/Question/TrueFalseQuestion.hpp"
#include "../Game/Question/TextQuestion.hpp"

#define CHECK_READ_FILE if ( inputFile . fail()) {cout << "Read from file failed" << endl; return false;}

using namespace std;

bool Importer::loadFromFile(string filename, vector<Quiz> & quizzes) {
	std::string input;
	ifstream inputFile( filename );
	CHECK_READ_FILE
	getline( inputFile, input );
	int quizNumber = atoi( input.c_str() );
	for ( int i = 0 ; i < quizNumber ; ++i ) {
		Quiz quiz = Importer::loadQuiz( inputFile );
		if ( quiz.mName.empty() ) {
			cout << "ERROR: Wrong file format" << endl;
			return false;
		}
		quizzes.push_back( quiz );
	}
	if (inputFile.eof()){
		return true;
	}
	getline( inputFile, input );

	if ( !input.empty() ) {
		quizzes.clear();
		cout << "ERROR: Wrong format of file" << endl;
		return false;
	}

	return true;
}

Quiz Importer::loadQuiz(std::ifstream & inputFile) {
	string dummy;
	getline( inputFile, dummy );
	if ( dummy != "Quiz" ) {
		return Quiz();
	}
	Quiz quiz;
	getline( inputFile, quiz.mName );
	getline( inputFile, quiz.mAuthor );
	int pageCount;
	getline( inputFile, dummy );
	pageCount = atoi( dummy.c_str() );

	if ( !loadTree( inputFile, quiz, pageCount ) ) {
		quiz.mName = "";
		return quiz;
	}

	for ( int i = 0 ; i < pageCount ; ++i ) {
		Importer::loadPageWithQuestions(inputFile, *quiz.mPages[i]);
	}

	return quiz;
}

bool Importer::loadTree(ifstream & inputFile, Quiz & quiz, int pageCount) {
	string dummy;
	int num1, num2;
	getline( inputFile, dummy );
	if ( dummy != "Tree:" ) {
		return false;
	}

	quiz.mPages.clear();

	getline( inputFile, dummy );
	num1 = atoi( dummy.c_str() );
	if ( num1 != 0 ) {
		return false;
	}
	auto pt = make_shared<Page>();
	quiz.mPages.push_back( pt );
	for ( int i = 1 ; i < pageCount ; ++i ) {
		getline(inputFile, dummy);
		char * toToken = strdup(dummy.c_str());
		num1 = atoi(toToken);
		toToken = strtok(toToken, ",");
		num2 = atoi(toToken);

		if ( num1 != i ) {
			return false;
		}
		auto ptr = make_shared<Page>();
		quiz.mPages.emplace_back( ptr );
		quiz.mPages[num2]->mBranches.push_back( quiz.mPages[i] );
	}
	return true;
}

bool Importer::loadPageWithQuestions(ifstream & inputFile, Page & page) {
	int questionCount;
	string dummy;
	bool branching = false;
	getline( inputFile, dummy ); // get "Page"
	getline( inputFile, dummy ); // get id
	getline( inputFile, dummy ); // get question count
	questionCount = atoi( dummy.c_str() );
	getline( inputFile, dummy ); // get branching bool
	if ( dummy == "1" ) {
		branching = true;
	}
	page.isBranching = branching;
	for ( int i = 0 ; i < questionCount ; ++i ) {
		page.mQuestions.push_back( Importer::loadQuestion( inputFile ) );
	}
	return true;
}

shared_ptr<Question> Importer::loadQuestion(ifstream & inputFile) {
	string dummy, dummy2;
	getline(inputFile, dummy);
	if (dummy != "Question"){
		return shared_ptr<Question>();
	}

	getline(inputFile, dummy);
	if ( dummy == "TrueFalseQuestion" ) {
		string question;
		getline(inputFile, question);
		getline(inputFile, dummy);
		bool answer = static_cast<bool>(atoi( dummy.c_str()));
		return make_shared<TrueFalseQuestion>(question, answer);
	} else if ( dummy == "TextQuestion" ) {
		string question, answer;
		getline(inputFile, question);
		getline(inputFile, answer);
		return make_shared<TextQuestion>(question, answer);
	} else if ( dummy == "MultiChoiceQuestion" ) {
		string question;
		getline(inputFile, question);
		vector<pair<string,bool>> choices;
		for (int i = 0; i < 4; ++i) {
			getline(inputFile, dummy);
			getline(inputFile, dummy2);
			pair<std::string,bool> choice(dummy, static_cast<bool>(atoi(dummy2.c_str())));
			choices.push_back(choice);
		}

		return make_shared<MultiChoiceQuestion>(question, choices);
	} else {
		cout << "Wrong question type: " << dummy << endl;
		return shared_ptr<Question>();
	}
}
