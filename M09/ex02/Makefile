CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++11
RM = rm -f
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

qsort: CCFLAGS += -DQSORT
qsort: fclean $(NAME)

all_containers: CCFLAGS += -DALL_CONTAINERS
all_containers: fclean $(NAME)

everything: CCFLAGS += -DQSORT -DALL_CONTAINERS
everything: fclean $(NAME)

sort: $(NAME)
	@echo "Sorting $(word 2, $(MAKECMDGOALS)) elements"
	@NUMBERS=$$(shuf -i 1-100000 -n $(word 2, $(MAKECMDGOALS)) | tr '\n' ' '); \
	./$(NAME) $$NUMBERS

verbose: $(NAME)
	@echo "Sorting $(word 2, $(MAKECMDGOALS)) elements"
	@NUMBERS=$$(shuf -i 1-100 -n $(word 2, $(MAKECMDGOALS)) | tr '\n' ' '); \
	./$(NAME) $$NUMBERS -v

run: $(NAME)
	@./$(NAME)

valgrind: $(NAME)
	@valgrind --leak-check=full ./$(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%:
	@:

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@