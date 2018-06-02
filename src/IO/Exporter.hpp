//
// Created by Tadeáš Valenta on 1.6.18.
//

#ifndef SEMESTRAL_PROJECT_EXPORTER_HPP
#define SEMESTRAL_PROJECT_EXPORTER_HPP


#include <iostream>
#include "../Game/Quiz.hpp"

namespace Exporter {
	bool exportToFile(std::string filename, std::vector<Quiz> & quizzes);


};


#endif //SEMESTRAL_PROJECT_EXPORTER_HPP
