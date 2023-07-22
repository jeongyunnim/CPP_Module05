#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::asciiTree = \
"                      ___\
				_,-'\"\"   \"\"\"\"`--.\
			 ,-'          __,,-- \\\
		   ,'    __,--\"\"\"\"dF      )\
		  /   .-\"Hb_,--\"\"dF      /\
		,'       _Hb ___dF\"-._,-'\
	  ,'      _,-\"\"\"\"   \"\"--..__\
	 (     ,-'                  `.\
	  `._,'     _   _             ;\
	   ,'     ,' `-'Hb-.___..._,-'\
	   \\    ,'\"Hb.-'HH`-.dHF\"\
		`--'   \"Hb  HH  dF\"\
				\"Hb HH dF\
				 \"HbHHdF\
				  |HHHF\
				  |HHH|\
				  |HHH|\
				  |HHH|\
				  |HHH|\
				  dHHHb\
				.dFd|bHb.               o\
	  o       .dHFdH|HbTHb.          o /\
\\  Y  |  \\__,dHHFdHH|HHhoHHb.__       Y\
##########################################";

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shurubery creation form", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (signFlag == false)
	{

	}
	else
	{
		std::ofstream	fout;
		std::string		fileName;

		fout.exceptions(std::ofstream::badbit);
		fileName = "./" + executor.getName() + "_shrubbery";
		try
		{
			fout.open(fileName);
		}
		catch (const std::ifstream::failure& e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
		fout << asciiTree;
		fout.close();
	}
}
