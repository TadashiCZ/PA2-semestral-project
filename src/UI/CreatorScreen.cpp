/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#include <algorithm>
#include <unistd.h>
#include "CreatorScreen.hpp"
#include "../Constants.hpp"
#include "../Game/Question/TrueFalseQuestion.hpp"
#include "../Game/Question/TextQuestion.hpp"
#include "../Game/Question/MultiChoiceQuestion.hpp"
#include "../Database/DataHandler.hpp"

using namespace std;

void lowerTheString(string & input) {
	std::transform( input.begin(), input.end(), input.begin(), ::tolower );
}

CreatorScreen::CreatorScreen(std::ostream & os) : mOs( os ) {}

void CreatorScreen::run() {
	show();
	interact();

}

void CreatorScreen::show() {
	mOs << COLOR_BLUE << "QUIZ ADDER 2000" << COLOR_RESET << endl;
}

void CreatorScreen::interact() {
	mOs << COLOR_YELLOW << "So you would like to create a quiz? (yes/no)" << COLOR_RESET << endl;
	while ( true ) {
		int num = yesNoInput();
		if ( num == 1 ) {
			break;
		} else if ( num == 0 ) {
			return;
		} else {
			mOs << "Just write yes or no. Nothing hard." << endl;
			continue;
		}
	}
	Quiz quiz;
	mOs << COLOR_YELLOW << "Okay! Let's do it! What will be the name of the quiz?" << COLOR_RESET << endl;
	quiz.mName = promptString();
	mOs << COLOR_YELLOW << quiz.mName << "? Great name for a quiz. And what is your name?" << COLOR_RESET << endl;
	quiz.mAuthor = promptString();
	mOs << COLOR_YELLOW << "Well nice to meet you " << quiz.mAuthor << "." << endl
	    << "And now something little bit more complicated. Structure of the quiz. But don't worry, I'll help you." << COLOR_RESET
	    << endl;
	int pageCount = loadTreeInteractive( quiz );
	mOs << COLOR_YELLOW << "This is you tree as whole. Pretty, right?" << endl << COLOR_RESET << quiz.printTree();

	mOs << COLOR_YELLOW << "Now comes the hard part. Filling up the pages with great questions." << COLOR_RESET << endl;


	for ( int i = 0 ; i < pageCount ; ++i ) {
		loadPageQuestionsInteractive( quiz.mPages[i], i );
	}

	quiz.printPageList();

	mOs << COLOR_YELLOW << "This is your quiz. Veeery pretty." << COLOR_RESET << endl;


	mOs << COLOR_YELLOW << "Do you want to add it or... " << COLOR_RED << "DESTROY IT?" << COLOR_YELLOW << "(Write add/destroy)"<< COLOR_RESET << endl;
	string dummy;
	while (true){
			cin >> dummy;
			lowerTheString(dummy);
			if (dummy == "add"){
				DataHandler::getInstance().mQuizzes.push_back( quiz );
				mOs << COLOR_YELLOW << "Okay. That's it. You'll find your quiz in the list now." << COLOR_RESET << endl;
				break;
			} else if (dummy == "destroy"){
				mOs << COLOR_YELLOW << "Your wish is my command. Destroying." << COLOR_RESET << endl;
				break;
			} else {
				mOs << COLOR_YELLOW << "Nope, not like this. Try again. Add or destroy." << COLOR_RESET << endl;
			}
	}



	mOs << COLOR_YELLOW << "Psst. Did you know it is easier to write the quize in the text file and than import it?"
	    << COLOR_RESET << endl;
}

int CreatorScreen::yesNoInput() {
	string dummy;
	cin >> dummy;
	lowerTheString( dummy );
	if ( dummy == "yes" ) {
		return 1;
	} else if ( dummy == "no" ) {
		return 0;
	} else {
		return -1;
	}
}

std::string CreatorScreen::promptString() {
	std::string dummy = "";
	char input[250];
	cin.ignore();
	while ( dummy.empty() ) {
		cin.getline(input, 249);
		dummy = input;
	}
	return dummy;
}

int CreatorScreen::loadTreeInteractive(Quiz & quiz) {
	string dummy;
	char c = ' ';
	int num1 = 1, num2 = 100, pageCount = 0;
	mOs << COLOR_YELLOW << "How many pages you quiz will have?" << COLOR_RESET << endl;

	while ( pageCount <= 0 ) {
		cin >> pageCount;
		if ( pageCount <= 0 ) {
			mOs << COLOR_RED << "Oh really? Now think for a while about what you did." << COLOR_RESET << endl;
			sleep( 2 );
		}
	}
	mOs << COLOR_YELLOW << "Your quiz will have " << pageCount;
	( pageCount == 1 ) ? mOs << " page." : mOs << " pages.";
	mOs << endl;
	auto pt = make_shared<Page>();
	quiz.mPages.push_back( pt );
	if ( pageCount == 1 ) {
		quiz.mPages[0]->mBranches.push_back( shared_ptr<Page>() );
		quiz.mPages[0]->mBranches.push_back( shared_ptr<Page>() );
		return pageCount;
	}


	mOs << "Now the quiz tree. You will start with the root page 0 by writing \"0,x\"" << endl
	    << "Try it now." << COLOR_RESET << endl;


	while ( num1 != 0 || dummy != ",x" ) {
		if ( cin >> num1 >> dummy ) {
			if ( num1 == 0 && dummy == ",x" ) {
				mOs << COLOR_YELLOW << "Great!" << COLOR_RESET << endl;
				break;
			}
			mOs << COLOR_YELLOW << "Are you really trying? 0,x and nothing more." << COLOR_RESET << endl;
		} else {
			mOs << COLOR_YELLOW << "Not like this! You broke it, oh good. Now I have to fix it again." << COLOR_RESET << endl;
			mOs << COLOR_RED << "FIXING YOUR MISTAKES... PLEASE WAIT." << COLOR_RESET << endl;
			sleep( 2 );
			cin.clear();
			cin.ignore();
			mOs << COLOR_YELLOW << "Now try it again." << COLOR_RESET << endl;
		}
	}


	mOs << COLOR_YELLOW << "And now you will put first the page number, comma and then the parent of that page." << endl
	    << "But make sure you input them from the lowest after 0 to the highest (1,2,3,...) and don't omit any. I will tell you when it's enough. :)"
	    << COLOR_RESET << endl;

	for ( int i = 1 ; i < pageCount ; ++i ) {
		while ( num1 != i || c != ',' || num2 >= i ) {
			if ( cin >> num1 >> c >> num2 ) {
				if ( num1 == i && c == ',' && num2 < i ) {
					mOs << COLOR_YELLOW << "Great! I now know about this relationship." << COLOR_RESET << endl;
					break;
				}
				mOs << COLOR_YELLOW << "Not like this. Try again." << COLOR_RESET << endl;
			} else {
				mOs << COLOR_YELLOW << "Not like this! You broke it, oh good. Now I have to fix it again." << COLOR_RESET << endl;
				mOs << COLOR_RED << "FIXING YOUR MISTAKES... PLEASE WAIT." << COLOR_RESET << endl;
				sleep( 2 );
				cin.clear();
				cin.ignore();
				mOs << COLOR_YELLOW << "Now try it again." << COLOR_RESET << endl;
			}
		}
		auto ptr = make_shared<Page>();
		quiz.mPages.push_back( ptr );
		quiz.mPages[num2]->mBranches.push_back( quiz.mPages[i] );
	}

	for ( int i = 1 ; i < pageCount ; ++i ) {
		switch ( quiz.mPages[i]->mBranches.size() ) {
			case 0: quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				break;
			case 1: quiz.mPages[i]->mBranches.push_back( shared_ptr<Page>() );
				break;
			default: quiz.mPages[i]->isBranching = true;
				break;
		}

	}
	mOs << COLOR_YELLOW
	    << "Good job! Now I know everything about love life of these pages."
	    << COLOR_RESET << endl;
	return pageCount;
}

void CreatorScreen::loadPageQuestionsInteractive(std::shared_ptr<Page> & page, int pageID) {
	int questionCount = 0;

	mOs << COLOR_YELLOW << "You are now going to fill page with ID " << pageID << " with questions." << COLOR_RESET << endl;
	mOs << COLOR_YELLOW << "How many questions should the page have?" << COLOR_RESET << endl;
	while ( questionCount <= 0 ) {
		cin >> questionCount;
		if ( questionCount <= 0 ) {
			mOs << COLOR_RED << "Really? Now think for a while about what you did." << COLOR_RESET << endl;
			sleep( 2 );
		}
	}

	mOs << COLOR_YELLOW << "This page will have " << questionCount << " question. Let's fill them up." << COLOR_RESET << endl;

	for ( int j = 0 ; j < questionCount ; ++j ) {
		if ( j == ( questionCount - 1 ) ) {
			mOs << COLOR_YELLOW
			    << "Now this will be the last question for this page.\n If it is branching, true = go with first branch, false = go with second."
			    << COLOR_RESET << endl;
		}
		auto ptr = loadQuestionInteractive();
		page->mQuestions.push_back( ptr );
	}


}

std::shared_ptr<Question> CreatorScreen::loadQuestionInteractive() {
	switch ( typeOfQuestion() ) {
		case TRUE_FALSE_QUESTION: return loadTrueFalseQuestion();
		case TEXT_QUESTION: return loadTextQuestion();
		case MULTI_CHOICE_QUESTION: return loadMultiChoiceQuestion();
	}
	return shared_ptr<Question>(nullptr);
}

int CreatorScreen::typeOfQuestion() {
	int input = 0;
	mOs << COLOR_YELLOW << "What type the question should be?\n"
	    << "    1) True/False Question\n"
	    << "    2) Text Question\n"
	    << "    3) MultiChoice Question\n" << COLOR_RESET << endl;

	while ( true ) {
		mOs << COLOR_YELLOW << "I want the number! Give it to me. Please?" << COLOR_RESET << endl;
		cin >> input;
		if ( input > 0 && input < 4 ) {
			break;
		}
	}
	return input;
}

std::shared_ptr<Question> CreatorScreen::loadTrueFalseQuestion() {
	std::string question, dummy;
	bool answer;
	char questionChar[250];
	mOs << COLOR_YELLOW << "So you want to have true or false question? 50/50? All right.\nWhat shall I be asking those nerds?"
	    << COLOR_RESET << endl;

	cin.ignore();
	while ( true ) {
		cin.getline( questionChar, 249 );
		question = questionChar;
		if ( question.length() > 5 ) {
			break;
		} else {
			mOs << COLOR_YELLOW << "That's too short for a real question, don't you think? Do better." << COLOR_RESET << endl;
		}
	}
	mOs << COLOR_YELLOW << "This one looks all right, I'll take it.\nBut is it true or false? You tell me."
	    << COLOR_RESET << endl;

	while ( true ) {
		cin >> dummy;
		lowerTheString( dummy );

		if ( dummy == "true" ) {
			answer = true;
			mOs << COLOR_YELLOW << "True it is." << COLOR_RESET << endl;
			break;
		} else if ( dummy == "false" ) {
			answer = false;
			mOs << COLOR_YELLOW << "False it is." << COLOR_RESET << endl;
			break;
		} else {
			mOs << COLOR_YELLOW << "No idea what it is." << COLOR_RESET << endl;
			continue;
		}
	}

	return make_shared<TrueFalseQuestion>( TrueFalseQuestion( question, answer ) );
}

std::shared_ptr<Question> CreatorScreen::loadTextQuestion() {
	std::string question, answer;
	char questionChar[250];
	char answerChar[50];
	mOs << COLOR_YELLOW << "So you want to have text question? Noted.\nWhat shall I be asking those trolls?" << COLOR_RESET
	    << endl;

	cin.ignore();
	while ( true ) {
		cin.getline( questionChar, 249 );
		question = questionChar;
		if ( question.length() > 5 ) {
			break;
		} else {
			mOs << COLOR_YELLOW << "That's too short for a real question, don't you think? Do better." << COLOR_RESET << endl;
		}
	}
	mOs << COLOR_YELLOW << "This one looks all right, I'll take it.\nBut what is the answer? I am no WATSON, you need to tell me."
	    << COLOR_RESET << endl;


	cin.getline( answerChar, 49 );
	answer = answerChar;


	mOs << COLOR_YELLOW << "Answer will be: \"" << answer << "\"." << COLOR_RESET << endl;


	return make_shared<TextQuestion>( TextQuestion( question, answer ) );
}

std::shared_ptr<Question> CreatorScreen::loadMultiChoiceQuestion() {
	std::string question, dummy1, dummy2;
	char questionChar[250];
	mOs << COLOR_YELLOW
	    << "MultiChoice? MultipleChoice? Guess you answer? Or several possible answers question?  All of them are correct.\n"
	       "But now I need the question, not the answer." << COLOR_RESET << endl;
	cin.ignore();
	while ( true ) {
		cin.getline( questionChar, 249 );
		question = questionChar;
		if ( question.length() > 5 ) {
			break;
		} else {
			mOs << COLOR_YELLOW << "That's too short for a real question, don't you think? Do better." << COLOR_RESET << endl;
		}
	}
	mOs << COLOR_YELLOW << "This one looks all right, I'll take it.\nNow the possible answers." << COLOR_RESET << endl;

	vector<pair<string, bool>> choices;
	for ( int i = 0 ; i < 4 ; ++i ) {
		mOs << COLOR_YELLOW << "What will the choice be?" << COLOR_RESET << endl;
		cin.ignore();
		char answerChar[250];
		cin.getline( answerChar, 249 );
		dummy1 = answerChar;

		mOs << COLOR_YELLOW << "And is this choice correct or not? Write true/false." << COLOR_RESET << endl;

		while ( true ) {
			cin >> dummy2;
			lowerTheString( dummy2 );
			if ( dummy2 == "true" ) {
				choices.push_back( make_pair<string, bool>( dummy1.c_str(), true ) );
				mOs << COLOR_YELLOW << "True it is." << COLOR_RESET << endl;
				break;
			} else if ( dummy2 == "false" ) {
				choices.push_back( make_pair<string, bool>( dummy1.c_str(), false ) );
				mOs << COLOR_YELLOW << "False it is." << COLOR_RESET << endl;
				break;
			} else {
				mOs << COLOR_YELLOW << "Okay... ones more. True or false." << COLOR_RESET << endl;
				continue;
			}
		}

	}

	return make_shared<MultiChoiceQuestion>( MultiChoiceQuestion( question, choices ) );
}



