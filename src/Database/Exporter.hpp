//
// Created by Tadeáš Valenta on 1.6.18.
//

#ifndef SEMESTRAL_PROJECT_EXPORTER_HPP
#define SEMESTRAL_PROJECT_EXPORTER_HPP


#include <iostream>
#include "../Game/Quiz.hpp"

/**
 * Functions to export quizzes into file
 */
namespace Exporter {
	/**
	 * Function to export given quizzes into file
	 * @param filename path to file where to store the quizzes
	 * @param quizzes container with quizzes to export
	 * @return true on success, false otherwise
	 */
	bool exportToFile(std::string filename, std::vector<Quiz> & quizzes);


}


#endif //SEMESTRAL_PROJECT_EXPORTER_HPP
