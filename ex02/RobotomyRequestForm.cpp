#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy request form", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else
	{
		std::srand(std::time(NULL));

		std::cout << CYAN << "VRRRRRRRRRrrrrrrrrrrrrr.." << RESET;
		if (std::rand() % 2 == 0)
		{
			std::cout << "\n" << MAGENTA << executor.getName() << BOLDWHITE << " has been successfully robotomized!" RESET << std::endl;
		}
		else
		{
			std::cout << BOLDRED << "Krrrrrrkkk!!" << RESET << MAGENTA << executor.getName() << WHITE << " robotomized failed.." << std::endl;
		}

	}
}