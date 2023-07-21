#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low: grade range is 1 - 150");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High: grade range is 1 - 150");
}

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}
int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_name = rhs._name;
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(int grade)
	: _name("* default *"), _grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(std::string name)
	: _name(name), _grade(150)
{
}

void Bureaucrat::increaseGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade -= 1;
	std::cout << _name << " is promoted. He is " << _grade << " now!" << std::endl;
}
void Bureaucrat::decreaseGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade += 1;
	std::cout << _name << " is demoted. He is " << _grade << " now.." << std::endl;
}

void Bureaucrat::signForm(Form &target) const
{
	try
	{
		target.beSigned(*this);
		std::cout << YELLOW << _name << BOLDWHITE << " Successfully Signed the " << YELLOW << target.getName() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << YELLOW << this->_name << RESET << " couldn't sign the <" << target.getName() << "> because grade is too low" << '\n';
	}
}

std::ostream &
operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}