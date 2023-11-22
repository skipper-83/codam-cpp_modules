CC = c++
CCFLAGS = -Wall -Werror -Wextra

RM = rm -f
SRCS = main.cpp ClapTrap.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = claptrap

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
