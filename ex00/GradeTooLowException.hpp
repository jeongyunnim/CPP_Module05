#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat::GradeTooLowException : std::exception
{
public:

	GradeTooLowException(void);

	const char* what() const throw();
};