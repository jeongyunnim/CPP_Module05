#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formType[3] = {"shrubbery creation", \
                                "robotomy request", \
                                "presidential pardon"};
    int i;
    for (i = 0; i < 3; i++)
    {
        if (formName == formType[i])
            break ;
    }
    //try를 어디서 해야 하는가???????
    switch (i)
    {
    case 0:
        return (new ShrubberyCreationForm(target));
    case 1:
        return (new RobotomyRequestForm(target));
    case 2:
        return (new PresidentialPardonForm(target));
    
    }

}

