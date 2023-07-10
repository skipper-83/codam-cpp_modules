CC = c++
CCFLAGS = -Wall -Werror -Wextra

RM = rm -f
SRCS = tests.cpp Account.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = account

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
