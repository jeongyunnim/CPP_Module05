#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	
	void execute(const Bureaucrat &executor) const;

private:
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
};