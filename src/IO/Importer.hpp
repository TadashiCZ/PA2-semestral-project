//
// Created by Tadeáš Valenta on 28.5.18.
//

#ifndef SEMESTRAL_PROJECT_IMPORTER_HPP
#define SEMESTRAL_PROJECT_IMPORTER_HPP

#include <iostream>
#include "../Game/Quiz.hpp"
#include "../Game/Question/Question.hpp"

/**
 * Namespace with functions to import
 */
namespace Importer {
	/**
	 * Loads quizzes from given file
	 * @param filename	filename to read from
	 * @param quizzes	vector of quiz files to save the quizzes loaded from the file to
	 * @return			true if reading the whole file was successful, false otherwise
	 */
bool loadFromFile(std::string filename, std::vector<Quiz> quizzes);

/**
 * Loads one quiz from filestream
 * @param inputString filestream to read from
 * @return quiz
 */
Quiz loadQuiz(std::ifstream & inputString);
Page loadPage(std::ifstream & inputString);
std::shared_ptr<Question> loadQuestion(std::ifstream & inputString);


};


#endif //SEMESTRAL_PROJECT_IMPORTER_HPP
