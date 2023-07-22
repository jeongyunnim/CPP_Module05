#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy request form", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy request form", 72, 45)
	, _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
	(void)rhs.getName();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (getSignFlag() == false)
		throw ExecuteBeforeSignException();
	else
	{
		struct timeval timeTemp;
		gettimeofday(&timeTemp, NULL);
		std::srand(timeTemp.tv_usec);

		std::cout << BOLDWHITE << "VRRRRRRRRRrrrrrrrrrrrrr......" << RESET;
		if (std::rand() % 2 == 0)
		{
			std::cout << "\n" << MAGENTA << _target << BOLDWHITE << " has been successfully robotomized!" RESET << std::endl;
		}
		else
		{
			std::cout << BOLDRED << "Krrrrrrkkk!! " << RESET << MAGENTA << _target << WHITE << " robotomized failed.." << std::endl;
		}

	}
}