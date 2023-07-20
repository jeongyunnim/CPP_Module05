#pragma once
#ifndef _GRADETOOHIGHEXCEPTION_HPP_
# define _GRADETOOHIGHEXCEPTION_HPP_

#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat::GradeTooHighException : std::exception
{
public:

	GradeTooHighException(void);

	const char* what() const throw();
};

#endif