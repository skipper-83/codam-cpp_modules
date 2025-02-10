CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

qsort: CCFLAGS += -DQSORT
qsort: $(NAME)

all_containers: CCFLAGS += -DALL_CONTAINERS
all_containers: fclean $(NAME)

everything: CCFLAGS += -DQSORT -DALL_CONTAINERS
everything: fclean $(NAME)

run: $(NAME)
	@./$(NAME)

valgrind: $(NAME)
	@valgrind --leak-check=full ./$(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@