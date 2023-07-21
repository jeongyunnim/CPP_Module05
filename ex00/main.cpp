#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *president;
	Bureaucrat *slave;

	std::cout << "\n-----------<<Constructor Grade Range Too High Exception Test>>-----------" << std::endl;
	try
	{
		president = new Bureaucrat("jeseo", 0);
		std::cout << *president << std::endl;
		delete president;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------<<Constructor Grade Range Too Low Exception Test>>-----------" << std::endl;
	try
	{
		slave = new Bureaucrat("slave", 151);
		std::cout << *slave << std::endl;
		delete slave;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------<<Increased Grade Range Too Low Exception Test>>-----------" << std::endl;
	try
	{
		slave = new Bureaucrat("slave", 130);
		std::cout << "present value: " << *slave << std::endl;
		while (1)
		{
			slave->decreaseGrade();
		}
		std::cout << *slave << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------<<Decreased Grade Range Too Low Exception Test>>-----------" << std::endl;
	try
	{
		slave = new Bureaucrat("slave", 20);
		std::cout << "present value: " << *slave << std::endl;
		while (1)
		{
			slave->increaseGrade();
		}
		std::cout << *slave << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}