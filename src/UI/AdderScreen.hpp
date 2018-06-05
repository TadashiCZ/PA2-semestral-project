/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#ifndef SEMESTRAL_PROJECT_ADDERSCREEN_HPP
#define SEMESTRAL_PROJECT_ADDERSCREEN_HPP


#include <iostream>
#include "Screen.hpp"
#include "../Game/Page.hpp"
#include "../Game/Quiz.hpp"

class AdderScreen : public Screen {
public:
	AdderScreen(std::ostream & os);
	virtual ~AdderScreen()= default;
	virtual void run();
	virtual void show();
	virtual void interact();
private:
	std::ostream & mOs;
	int yesNoInput();
	std::string promptString();
	int loadTreeInteractive(Quiz & quiz);
	void loadPageQuestionsInteractive(std::shared_ptr<Page> & shared_ptr, int pageID);
	std::shared_ptr<Question> loadQuestionInteractive();
	int typeOfQuestion();
	std::shared_ptr<Question> loadTrueFalseQuestion();
	std::shared_ptr<Question> loadTextQuestion();
	std::shared_ptr<Question> loadMultiChoiceQuestion();
};


#endif //SEMESTRAL_PROJECT_ADDERSCREEN_HPP
