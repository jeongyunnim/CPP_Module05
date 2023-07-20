#pragma once
#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{

public:
	
	class GradeTooLowException;
	class GradeTooHighException;

	const std::string&	getName(void) const;
	int					getGrade(void) const;

	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	Bureaucrat(const Bureaucrat& other);
	
	Bureaucrat(std::string name, int grade);
	Bureaucrat(int grade);
	Bureaucrat(std::string name);
	void	increaseGrade(void);
	void	decreaseGrade(void);

private:

	Bureaucrat(void);
	std::string _name;
	int			_grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif