CC = c++
CCFLAGS = -Wall -Werror -Wextra

RM = rm -f
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = triangle

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

run : $(NAME)
	@./$(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)
	$(RM) bsp.hpp

fclean : clean
	$(RM) $(NAME)
