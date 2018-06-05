//
// Created by Tadeáš Valenta on 14.5.18.
//
#ifndef SEMESTRAL_PROJECT_SCREEN_HPP
#define SEMESTRAL_PROJECT_SCREEN_HPP

/**
 * Abstract class used as interface for all Screen classes
 */
class Screen {
public:
	virtual ~Screen()= default;
	/**
	 * Default method to run for the screen to start
	 */
	virtual void run()=0;

private:
	/**
	 * Shows static contect of Screen (headers, menus, etc.)
	 */
	virtual void show()=0;

	/**
	 * interacts with the user
	 */
	virtual void interact()=0;
};


#endif //SEMESTRAL_PROJECT_SCREEN_HPP
