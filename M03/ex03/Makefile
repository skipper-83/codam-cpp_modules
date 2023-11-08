CC = c++
CCFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98	

RM = rm -f
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = diamond

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
