//
// Created by Tadeáš Valenta on 14.5.18.
//
#ifndef SEMESTRAL_PROJECT_ADDERSCREEN_HPP
#define SEMESTRAL_PROJECT_ADDERSCREEN_HPP


#include <iostream>
#include "Screen.hpp"
#include "../Game/Page.hpp"
#include "../Game/Quiz.hpp"

/**
 * Screen for creating new quiz
 */
class CreatorScreen : public Screen {
public:
	/**
	 * Creates screen, output will be streamed into given stream
	 * @param os
	 */
	CreatorScreen(std::ostream & os);
	virtual ~CreatorScreen()= default;
	virtual void run();
private:
	virtual void show();
	virtual void interact();
	std::ostream & mOs;
	/**
	 * Accepts yes no input
	 * @return 1 on yes, 0 on no, -1 on else
	 */
	int yesNoInput();

	/**
	 * Prompts user to input string
	 * @return
	 */
	std::string promptString();

	/**
	 * Walks the user trough creating the tree of pages of quiz
	 * @param quiz quiz which will be pages loaded in
	 * @return count of pages
	 */
	int loadTreeInteractive(Quiz & quiz);

	/**
	 * Walk the user through loading questions for given page
	 * @param page pointer to page to load the questions in
	 * @param pageID id of page in quiz
	 */
	void loadPageQuestionsInteractive(std::shared_ptr<Page> & page, int pageID);

	/**
	 * Walks the user through loading one question
	 * @return pointer to the new question
	 */
	std::shared_ptr<Question> loadQuestionInteractive();

	/**
	 * Prompts the user to input type of question
	 * @return
	 */
	int typeOfQuestion();

	/**
	 * Walks the user through input of true/false questions
	 * @return pointer to created question
	 */
	std::shared_ptr<Question> loadTrueFalseQuestion();

	/**
	 * Walks the user through input of text questions
	 * @return pointer to created question
	 */
	std::shared_ptr<Question> loadTextQuestion();

	/**
	 * Walks the user through input of multichoice questions
	 * @return pointer to created question
	 */
	std::shared_ptr<Question> loadMultiChoiceQuestion();
};


#endif //SEMESTRAL_PROJECT_ADDERSCREEN_HPP
