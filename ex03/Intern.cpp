#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

static void nouppercaseString(std::string& formName)
{
	for (std::string::iterator it = formName.begin(); it != formName.end(); it++)
	{
		if ('A' <= *it && *it <= 'Z')
			*it += 32;
	}
}

AForm* Intern::makeForm(std::string formName, const std::string& target)
{
	std::string formType[3] = {"shrubbery creation", \
								"robotomy request", \
								"presidential pardon"};
	int i;

	nouppercaseString(formName);
	for (i = 0; i < 3; i++)
	{
		if (formName == formType[i])
			break ;
	}
	switch (i)
	{
	case 0:
		return (new ShrubberyCreationForm(target));
	case 1:
		return (new RobotomyRequestForm(target));
	case 2:
		return (new PresidentialPardonForm(target));
	default:
		std::cerr << RED << "Error: Invalid type form " << formName << RESET << std::endl;
		return (NULL);
	}
}

