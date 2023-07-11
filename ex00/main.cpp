#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat president(1);
	Bureaucrat maggot(150);
	Bureaucrat errorInstanceHigh(151);
	Bureaucrat errorInstanceLow(0);


	std::cout << "initial value, insertion operator overloading test\n" << std::endl;
	std::cout << president << std::endl;
	std::cout << maggot << std::endl;

	std::cout << "\nexception test\n" << std::endl;

	president.increaseGrade(); // too high error
	maggot.decreaseGrade(); // too low error

	std::cout << president << std::endl;
	std::cout << maggot << std::endl;

	Bureaucrat test(51);
	std::cout << test << std::endl;
	for (int i = 0; i < 50; i++)
	{
		test.increaseGrade();
	}
	std::cout << test << std::endl;

	return (0);
}