CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

NAME = btc

all : $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

run : $(NAME)
	@./$(NAME)

subject_input : $(NAME)
	@./$(NAME) subj_input.csv

own_input : $(NAME)
	@./$(NAME) input.csv

valgrind : $(NAME)
	@valgrind --leak-check=full ./$(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
