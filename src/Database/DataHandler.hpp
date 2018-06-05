//
// Created by Tadeáš Valenta on 27.5.18.
//

#ifndef SEMESTRAL_PROJECT_EXPOIMPO_H
#define SEMESTRAL_PROJECT_EXPOIMPO_H


#include "../Game/Quiz.hpp"

/**
 * Singleton class to hold and IO app data.
 */
class DataHandler {
public:
	/**
	 * Member holding the quizzes loaded in the game
	 */
	std::vector<Quiz> mQuizzes;

	/**
	 * Getter of static instance (creates new one if first call
	 * @return the only living instance of Data Handler
	 */
	static DataHandler & getInstance();

	/**
	 * Shows Export/Import menu to the user
	 */
	void runIO();

	/**
	 * Interacts with user to export quizzes tofile
	 * @return true on success, false otherwise
	 */
	bool exportQuizzes();

	/**
	 * Used to export quizzes when closing the quiz
	 * @return true on succes, false otherwise
	 */
	bool saveQuizData();

	DataHandler(DataHandler const &) = delete;
	void operator=(DataHandler const &) = delete;

private:
	/**
	 * Prints IO menu
	 * @return 1 for import, 2 for export, -1 for exit the whole app
	 */
	int IOMenu();

	/**
	 * Prompts filepath and returns it
	 * @return
	 */
	std::string static promptFilename();

	/**
	 * Interacts with user to import quizzes from file
	 * @return true on success, false otherwise
	 */
	bool importQuizzes();

	/**
	 * Default constructor
	 */
	DataHandler() = default;

	int addQuizForExportInteractive(std::vector<Quiz> & forExport);
	void showQuizList();
};


#endif //SEMESTRAL_PROJECT_EXPOIMPO_H
