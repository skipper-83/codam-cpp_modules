CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98 

RM = rm -f
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = bureaucrat_with_abstract_form

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

run : $(NAME)
	@./$(NAME)

valgrind : $(NAME)
	@valgrind --leak-check=full ./$(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)
	$(RM) *_shrubbery

fclean : clean
	$(RM) $(NAME)
