#include <iostream>
#include <string>

class Bureaucrat
{

public:

	const std::string&	getName(void) const;
	int					getGrade(void) const;

	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	Bureaucrat(const Bureaucrat& other);
	
	Bureaucrat(std::string name, int grade);
	void	increaseGrade(void);
	void	decreaseGrade(void);

private:

	std::string _name;
	int			_grade;

};