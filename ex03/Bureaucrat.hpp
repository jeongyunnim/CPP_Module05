#pragma once
#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <exception>
#include <string>

#define RESET "\033[0m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

#define BACKGROUND_BLACK "\033[40m"
#define BACKGROUND_RED "\033[41m"
#define BACKGROUND_GREEN "\033[42m"
#define BACKGROUND_YELLOW "\033[43m"
#define BACKGROUND_BLUE "\033[44m"
#define BACKGROUND_MAGENTA "\033[45m"
#define BACKGROUND_CYAN "\033[46m"
#define BACKGROUND_WHITE "\033[47m"

class AForm;

class Bureaucrat
{

public:
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	const std::string &getName(void) const;
	int getGrade(void) const;

	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, int grade);
	Bureaucrat(int grade);
	Bureaucrat(std::string name);
	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(AForm &target) const;
	void executeForm(const AForm &target) const;

private:
	Bureaucrat(void);
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif