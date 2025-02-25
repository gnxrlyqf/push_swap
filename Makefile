CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
SRC = $(wildcard src/*.c)
BONUS = $(wildcard bonus/*.c) $(filter-out src/main.c, $(SRC))
NAME = push_swap
BNAME = checker

.PHONY: all clean fclean re bonus
.SECONDARY:

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $^ $(INC) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BONUS:.c=.o)
	$(CC) $^ $(INC) -o $(BNAME)

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(SRC:.c=.o) $(BONUS:.c=.o)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all