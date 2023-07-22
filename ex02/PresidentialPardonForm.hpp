#pragma once
#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	
	PresidentialPardonForm(const std::string& target);
	void execute(const Bureaucrat &executor) const;

private:
	PresidentialPardonForm& operator=(PresidentialPardonForm& rhs);
	std::string _target;
};

#endif