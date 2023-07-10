CC = c++
CCFLAGS = -Wall -Werror -Wextra

RM = rm -f
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = zombiehorde

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

run : $(NAME)
	@./$(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
