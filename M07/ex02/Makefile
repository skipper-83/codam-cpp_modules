CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98 

RM = rm -f
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INTRA_SRCS = main_intra.cpp
INTRA_OBJS = $(patsubst %.cpp, %.o, $(INTRA_SRCS))

NAME = array_template

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

intra: $(INTRA_OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(INTRA_OBJS)

run : $(NAME)
	@./$(NAME)

valgrind : $(NAME)
	@valgrind --leak-check=full ./$(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
