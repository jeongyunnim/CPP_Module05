#pragma once
#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class AForm
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

	~AForm(void);
	AForm(const AForm &other);

	AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

	void beSigned(const Bureaucrat &target);

private:
	AForm &operator=(const AForm &rhs);
	const std::string _name;
	const int _requiredGradeToSign;
	const int _requiredGradeToExecute;
	bool _signFlag;

	AForm(void);
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif