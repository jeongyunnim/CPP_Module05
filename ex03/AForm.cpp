#include "AForm.hpp"

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low: grade range is 1 - 150 or Grade is lower than required");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high: grade range is 1 - 150");
}

const char *AForm::ExecuteBeforeSignException::what() const throw()
{
	return ("Form is not signed: only signed forms can be executed.");
}

const std::string &AForm::getName(void) const
{
	return (_name);
}
int AForm::getRequiredGradeToSign(void) const
{
	return (_requiredGradeToSign);
}

int AForm::getRequiredGradeToExecute(void) const
{
	return (_requiredGradeToExecute);
}

bool AForm::getSignFlag(void) const
{
	return (_signFlag);
}

AForm::AForm(void)
	: _name("* default Aform *"), _requiredGradeToSign(150), _requiredGradeToExecute(150), _signFlag(false)
{
}

AForm::~AForm(void) {}

AForm &AForm::operator=(AForm &rhs)
{
	(void)rhs._name;
	return (*this);
}

AForm::AForm(const AForm &other)
	: _name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute), _signFlag(other._signFlag)
{
}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute)
	: _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute), _signFlag(false)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned(const Bureaucrat &target)
{
	if (_requiredGradeToSign < target.getGrade())
	{
		throw GradeTooLowException();
	}
	_signFlag = true;
	return;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
	out << YELLOW << "[" << rhs.getName() << "]" << RESET << " AForm requires following grades "
		<< BLUE << "For Sign: " << GREEN << rhs.getRequiredGradeToSign() << BLUE << " For Execute: " << GREEN << rhs.getRequiredGradeToExecute() << RESET;
	return (out);
}