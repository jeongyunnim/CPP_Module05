#pragma once
#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:

	Intern(void);
	~Intern(void);
	AForm *makeForm(std::string formName, const std::string& target);

private:

	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);

};

#endif