#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential pardon form", 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox"
	}
}