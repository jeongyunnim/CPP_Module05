#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}
int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	_name = rhs._name;
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}
	
Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name)
	,	_grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 100)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(int grade)
	:	_name("* default *")
	,	_grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 100)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(std::string name)
	:	_name(name)
	,	_grade(100)
{}

void	Bureaucrat::increaseGrade(void)
{

}
void	Bureaucrat::decreaseGrade(void)
{

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}