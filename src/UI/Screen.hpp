/**
* Created by Tadeáš Valenta on 3.6.18.
*/
#ifndef SEMESTRAL_PROJECT_SCREEN_HPP
#define SEMESTRAL_PROJECT_SCREEN_HPP


class Screen {
public:
	virtual ~Screen()= default;
	virtual void run()=0;
	virtual void show()=0;
	virtual void interact()=0;
};


#endif //SEMESTRAL_PROJECT_SCREEN_HPP
