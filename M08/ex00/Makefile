CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98 

RM = rm -f
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = easyfind

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
