#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void leak()
{
	system("leaks $PPID");
}

int main()
{
	Bureaucrat	*bureaucrats[4];
	AForm		*forms[3];
	AForm *shrubberyCreationTest[5];

	atexit(leak);
	bzero(bureaucrats, sizeof(bureaucrats));
	bzero(forms, sizeof(forms));
	std::cout << BOLDWHITE << "\n-----------<<Form Test>>-----------" << RESET << std::endl;
	try
	{
		Intern intern;

		bureaucrats[0] = new Bureaucrat("president", 1);
		bureaucrats[1] = new Bureaucrat("some bureaucrat of grade 45", 45);
		bureaucrats[2] = new Bureaucrat("some bureaucrat of grade 80", 80);
		bureaucrats[3] = new Bureaucrat("criminal", 150);
		forms[0] = intern.makeForm("Shrubbery creation", "jeseo's backyard");
		forms[1] = intern.makeForm("robotomy request", "evaluator");
		forms[2] = intern.makeForm("PRESIDENTIAL PARDON", "Hong gil-dong");

		std::cout << "\n\nGrade 1 tyring to execute not signed form\n1.[X] 2.[X] 3.[X]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[0]->excuteForm(*forms[i]);
		}

		bureaucrats[0]->signForm(*forms[0]);
		bureaucrats[2]->excuteForm(*forms[0]);

		std::cout << "\n\ngrade 80 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[X] 3.[X]/[X]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[2]->signForm(*forms[i]);
			bureaucrats[2]->excuteForm(*forms[i]);
		}

		std::cout << "\n\ngrade 45 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[O] 3.[X]/[X]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[1]->signForm(*forms[i]);
			bureaucrats[1]->excuteForm(*forms[i]);
		}

		std::cout << "\n\ngrade 1 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[O] 3.[O]/[O]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[0]->signForm(*forms[i]);
			bureaucrats[0]->excuteForm(*forms[i]);
		}

		std::cout << "\n\ngrade 150 tyring to sign not signed form\n1.[X]/[X] 2.[X]/[X] 3.[X]/[X]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[3]->signForm(*forms[i]);
			bureaucrats[2]->excuteForm(*forms[i]);
		}

		std::cout << BOLDWHITE << "\n-----------<<Shrubbery creation form Test>>-----------" << RESET << std::endl;

		shrubberyCreationTest[0] = intern.makeForm("shrubbery creation", "1cluster");
		shrubberyCreationTest[1] = intern.makeForm("shrubbery creation", "2cluster");
		shrubberyCreationTest[2] = intern.makeForm("shrubbery creation", "3cluster");
		shrubberyCreationTest[3] = intern.makeForm("shrubbery creation", "4cluster");
		shrubberyCreationTest[4] = intern.makeForm("shrubbery creation", "5cluster");
		for (int i = 0; i < 5; i++)
		{
			shrubberyCreationTest[i]->beSigned(*bureaucrats[0]);
			bureaucrats[0]->excuteForm(*shrubberyCreationTest[i]);
			delete shrubberyCreationTest[i];
			shrubberyCreationTest[i] = NULL;
		}

		std::cout << BOLDWHITE << "\n-----------<<Invalid type form Test>>-----------" << RESET << std::endl;
		intern.makeForm("settingLunchMenu", "pizza");
		intern.makeForm("settingLunchMenu", "hamburger");
		intern.makeForm("cluster tour", "Cadet");
		intern.makeForm("evaluation", "evaluator");

		for (int i = 0; i < 4; i++)
			delete bureaucrats[i];
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		
		for (int i = 0; i < 5; i++)
		{
			if (shrubberyCreationTest[i] != NULL)
				delete shrubberyCreationTest[i];
		}

		for (int i = 0; i < 4; i++)
		{
			if (bureaucrats[i] != NULL)
				delete bureaucrats[i];
		}
		for (int i = 0; i < 3; i++)
		{
			if (forms[i] != NULL)
				delete forms[i];
		}
	}

	return (0);
}