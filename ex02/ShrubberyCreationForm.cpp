#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::_asciiTree = \
"                      ___\n\
				_,-'\"\"   \"\"\"\"`--.\n\
			 ,-'          __,,-- \\\n\
		   ,'    __,--\"\"\"\"dF      )\n\
		  /   .-\"Hb_,--\"\"dF      /\n\
		,'       _Hb ___dF\"-._,-'\n\
	  ,'      _,-\"\"\"\"   \"\"--..__\n\
	 (     ,-'                  `.\n\
	  `._,'     _   _             ;\n\
	   ,'     ,' `-'Hb-.___..._,-'\n\
	   \\    ,'\"Hb.-'HH`-.dHF\"\n\
		`--'   \"Hb  HH  dF\"\n\
				\"Hb HH dF\n\
				 \"HbHHdF\n\
				  |HHHF\n\
				  |HHH|\n\
				  |HHH|\n\
				  |HHH|\n\
				  |HHH|\n\
				  dHHHb\n\
				.dFd|bHb.               o\n\
	  o       .dHFdH|HbTHb.          o /\n\
\\  Y  |  \\__,dHHFdHH|HHhoHHb.__       Y\n\
##########################################\n";

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shurubery creation form", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shurubery creation form", 145, 137)
	, _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
	(void)rhs.getName();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (getSignFlag() == false)
		throw ExecuteBeforeSignException();
	else
	{
		std::ofstream	fout;
		std::string		fileName;

		fout.exceptions(std::ofstream::badbit);
		fileName = "./" + _target + "_shrubbery";
		try
		{
			fout.open(fileName);
		}
		catch (const std::ifstream::failure& e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
		fout << _asciiTree;
		fout.close();
	}
}
