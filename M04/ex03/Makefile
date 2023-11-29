CC = c++
CCFLAGS = -g -Wall -Werror -Wextra -std=c++98

RM = rm -f
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp BlankMateria.cpp Character.cpp MateriaSource.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = materia

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

fclean : clean
	$(RM) $(NAME)
