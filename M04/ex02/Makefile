CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f
SRCS = main.cpp Cat.cpp Dog.cpp AAnimal.cpp Brain.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = absract_animals

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
