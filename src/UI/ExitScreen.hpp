//
// Created by Tadeáš Valenta on 14.5.18.
//
#ifndef SEMESTRAL_PROJECT_EXITSCREEN_HPP
#define SEMESTRAL_PROJECT_EXITSCREEN_HPP


#include "Screen.hpp"

/**
 * Screen which says goodbye to the user
 */
class ExitScreen : public Screen {

public:
	/**
	 * Creates screen, output will be streamed into given stream
	 * @param os
	 */
	ExitScreen(std::ostream & os);
	virtual ~ExitScreen()= default;
	virtual void run() override;
private:
	virtual void show() override;
	virtual void interact() override;
	std::ostream & mOs;

};


#endif //SEMESTRAL_PROJECT_EXITSCREEN_HPP
