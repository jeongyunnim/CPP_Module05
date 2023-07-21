#include "Form.hpp"

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low: grade range is 1 - 150");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High: grade range is 1 - 150");
}

const std::string &Form::getName(void) const
{
	return (_name);
}
int Form::getRequiredGradeToSign(void) const
{
	return (_requiredGradeToSign);
}

int Form::getRequiredGradeToExecute(void) const
{
	return (_requiredGradeToExecute);
}

Form::Form(void)
	: _name("* default form *"), _requiredGradeToSign(150), _requiredGradeToExecute(150), _signFlag(false)
{
}

Form::~Form(void) {}

Form &Form::operator=(const Form &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	std::string &_nameTemp = const_cast<std::string &>(_name);
	int &_requiredGradeToSignTemp = const_cast<int &>(_requiredGradeToSign);
	int &_requiredGradeToExecuteTemp = const_cast<int &>(_requiredGradeToExecute);

	_nameTemp = rhs._name;
	_requiredGradeToSignTemp = rhs._requiredGradeToSign;
	_requiredGradeToExecuteTemp = rhs._requiredGradeToExecute;

	return (*this);
}

Form::Form(const Form &other)
	: _name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute), _signFlag(other._signFlag)
{
}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute)
	: _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute), _signFlag(false)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

void Form::beSigned(const Bureaucrat &target)
{
	if (_requiredGradeToSign < target.getGrade())
	{
		throw GradeTooLowException();
	}
	_signFlag = true;
	return;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	out << YELLOW << "[" << rhs.getName() << "]" << RESET << " Form requires following grades "
		<< BLUE << "For Sign: " << GREEN << rhs.getRequiredGradeToSign() << BLUE << " For Execute: " << GREEN << rhs.getRequiredGradeToExecute() << RESET;
	return (out);
}