/**
* Created by Tadeáš Valenta on 4.6.18.
*/
#ifndef SEMESTRAL_PROJECT_EXITSCREEN_HPP
#define SEMESTRAL_PROJECT_EXITSCREEN_HPP


#include "Screen.hpp"

class ExitScreen : public Screen {

public:
	ExitScreen(std::ostream & os);
	virtual ~ExitScreen()= default;
	virtual void run() override;
	virtual void show() override;
	virtual void interact() override;
protected:
	std::ostream & mOs;

};


#endif //SEMESTRAL_PROJECT_EXITSCREEN_HPP
