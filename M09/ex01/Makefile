CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++11

RM = rm -f
SRCS = main.cpp RPN.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = RPN

all : $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

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
