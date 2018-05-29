//
// Created by Tadeáš Valenta on 28.5.18.
//

#ifndef SEMESTRAL_PROJECT_IMPORTER_HPP
#define SEMESTRAL_PROJECT_IMPORTER_HPP

#include <iostream>
#include "../Game/Quiz.hpp"
#include "../Game/Question/Question.hpp"

/**
 * Namespace with import
 */
namespace Importer {
	/**
	 * Loads quizzes from given file.
	 * @param filename	filename to read from
	 * @param quizzes	vector of quiz files to save the quizzes loaded from the file to
	 * @return			true if reading the whole file was successful, false otherwise
	 */
	bool loadFromFile(std::string filename, std::vector<Quiz> quizzes);

/**
 * Loads one quiz from file stream.
 * @param 	inputString file stream to read from
 * @return 	quiz read from file stream
 */
	Quiz loadQuiz(std::ifstream & inputFile);
/**
 * Loads one page from file stream.
 * @param 	inputFile file stream to read from
 * @return 	page read from file stream
 */
	Page loadPage(std::ifstream & inputFile);

/**
 * Loads one question from file stream.
 * @param 	inputFile file stream to read from
 * @return 	shared pointer to Question read from file stream (if nullptr returned, read failed)
 */
	std::shared_ptr<Question> loadQuestion(std::ifstream & inputFile);
};


#endif //SEMESTRAL_PROJECT_IMPORTER_HPP
