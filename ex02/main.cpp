#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	*bureaucrats[4];
	AForm		*forms[3];

	std::cout << BOLDWHITE << "\n-----------<<Form Test>>-----------" << RESET << std::endl;
	try
	{
		bureaucrats[0] = new Bureaucrat("president", 1);
		bureaucrats[1] = new Bureaucrat("some bureaucrat of grade 45", 45);
		bureaucrats[2] = new Bureaucrat("some bureaucrat of grade 80", 80);
		bureaucrats[3] = new Bureaucrat("criminal", 150);
		forms[0] = new ShrubberyCreationForm("jeseo's backyard");
		forms[1] = new RobotomyRequestForm("evaluator");
		forms[2] = new PresidentialPardonForm("gil-dong Hong");

		std::cout << "\n\nGrade 1 tyring to execute not signed form\n1.[X] 2.[X] 3.[X]" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			bureaucrats[0]->excuteForm(*forms[i]);
		}

		bureaucrats[0]->signForm(*forms[0]);
		bureaucrats[2]->excuteForm(*forms[0]);

		// std::cout << "\n\ngrade 80 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[X] 3.[X]/[X]" << std::endl;
		// for (int i = 0; i < 3; i++)
		// {
		// 	bureaucrats[2]->signForm(*forms[i]);
		// 	bureaucrats[2]->excuteForm(*forms[i]);
		// }

		// std::cout << "\n\ngrade 45 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[O] 3.[X]/[X]" << std::endl;
		// for (int i = 0; i < 3; i++)
		// {
		// 	bureaucrats[1]->signForm(*forms[i]);
		// 	bureaucrats[1]->excuteForm(*forms[i]);
		// }

		// std::cout << "\n\ngrade 1 tyring to sign not signed form\n1.[O]/[O] 2.[O]/[O] 3.[O]/[O]" << std::endl;
		// for (int i = 0; i < 3; i++)
		// {
		// 	bureaucrats[0]->signForm(*forms[i]);
		// 	bureaucrats[0]->excuteForm(*forms[i]);
		// }

		// std::cout << "\n\ngrade 150 tyring to sign not signed form\n1.[X]/[X] 2.[X]/[X] 3.[X]/[X]" << std::endl;
		// for (int i = 0; i < 3; i++)
		// {
		// 	bureaucrats[3]->signForm(*forms[i]);
		// 	bureaucrats[2]->excuteForm(*forms[i]);
		// }

		// std::cout << BOLDWHITE << "\n-----------<<Randomness Test>>-----------" << RESET << std::endl;
		// for (int i = 0; i < 15; i++)
		// {
		// 	std::cout << "\n[" << i + 1 << "]" << std::endl;
		// 	bureaucrats[0]->excuteForm(*forms[1]);
		// }

		delete bureaucrats[0];
		delete bureaucrats[1];
		delete bureaucrats[2];
		delete bureaucrats[3];
		delete forms[0];
		delete forms[1];
		delete forms[2];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}