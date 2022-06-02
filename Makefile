SRC = $(shell find src -name "*.c")

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	gcc -pthread -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
