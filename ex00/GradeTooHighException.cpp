#include "GradeTooHighException.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High: grade range is 1 - 100");
}
