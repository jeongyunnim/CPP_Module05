#pragma once
#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
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
	int getRequiredGradeToSign(void) const;
	int getRequiredGradeToExecute(void) const;

	~Form(void);
	Form &operator=(const Form &rhs);
	Form(const Form &other);

	Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

	void beSigned(const Bureaucrat &target);

private:
	const std::string _name;
	const int _requiredGradeToSign;
	const int _requiredGradeToExecute;
	bool _signFlag;

	Form(void);
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif