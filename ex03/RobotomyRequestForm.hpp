#pragma once
#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include <cstdlib>
#include <sys/time.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	
	RobotomyRequestForm(const std::string& target);
	void execute(const Bureaucrat &executor) const;

private:
	RobotomyRequestForm& operator=(RobotomyRequestForm& rhs);
	static const char* asciiTree;
	std::string _target;
};

#endif