#ifndef _GRADETOOLOWEXCEPTION_HPP_
# define _GRADETOOLOWEXCEPTION_HPP_
#include "GradeTooLowException.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low: grade range is 1 - 100");
}

#endif