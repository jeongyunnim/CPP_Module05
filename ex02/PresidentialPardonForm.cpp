#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential pardon form", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm("Presidential pardon form", 25, 5)
	,	_target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& rhs)
{
	(void)rhs.getName();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (getSignFlag() == false)
		throw ExecuteBeforeSignException();
	else
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}