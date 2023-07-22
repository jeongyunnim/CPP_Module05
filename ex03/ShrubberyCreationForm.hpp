#pragma once
#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	
	ShrubberyCreationForm(const std::string& target);
	void execute(const Bureaucrat &executor) const;

private:
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& rhs);
	static const char* _asciiTree;
	std::string _target;
};

#endif