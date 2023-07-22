NAME 		=	ex02

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./Bureaucrat.hpp\
				./AForm.hpp\
				./ShrubberyCreationForm.hpp\
				./RobotomyRequestForm.hpp\
				./PresidentialPardonForm.hpp\
				
SRCS		=	./main.cpp\
				./Bureaucrat.cpp\
				./AForm.cpp\
				./ShrubberyCreationForm.cpp\
				./RobotomyRequestForm.cpp\
				./PresidentialPardonForm.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re