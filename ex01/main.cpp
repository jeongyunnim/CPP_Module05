#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat president("jeseo", 1);
	Bureaucrat slave("slave", 150);
	Form *settingLunchMenu;

	std::cout << "\n-----------<<Constructor Grade Range Too High Exception Test>>-----------" << std::endl;
	try
	{
		std::cout << "sign value is 0 -> It has to occur too high exception" << std::endl;
		settingLunchMenu = new Form("setting lunch menu", 0, 150);
		delete settingLunchMenu;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "execute value is 0 -> It has to occur too high exception" << std::endl;
		settingLunchMenu = new Form("setting lunch menu", 0, 150);
		delete settingLunchMenu;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------<<Constructor Grade Range Too Low Exception Test>>-----------" << std::endl;
	try
	{
		std::cout << "sign value is 151 -> It has to occur too low exception" << std::endl;
		settingLunchMenu = new Form("setting lunch menu", 151, 1);
		delete settingLunchMenu;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "execute value is 151 -> It has to occur too low exception" << std::endl;
		settingLunchMenu = new Form("setting lunch menu", 1, 151);
		delete settingLunchMenu;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------<<Sign Test>>-----------" << std::endl;
	try
	{
		settingLunchMenu = new Form("setting lunch menu", 50, 20);
		std::cout << *settingLunchMenu << std::endl;
		president.signForm(*settingLunchMenu);
		slave.signForm(*settingLunchMenu);
		delete settingLunchMenu;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form electPresident("elect president", 10, 150);
		Form nominateSomeone("nominate someone", 150, 150);
		std::cout << electPresident << std::endl;
		president.signForm(electPresident);
		slave.signForm(electPresident);
		std::cout << nominateSomeone << std::endl;
		president.signForm(nominateSomeone);
		slave.signForm(nominateSomeone);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}