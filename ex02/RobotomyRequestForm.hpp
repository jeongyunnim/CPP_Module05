#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	
	void execute(const Bureaucrat &executor) const;

private:
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	static const char* asciiTree;
};