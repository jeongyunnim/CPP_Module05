#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	
	void execute(const Bureaucrat &executor) const;

private:
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	static const char* asciiTree;
};