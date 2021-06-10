NAME = pipex

SRC = pipex.c pipex_utils.c exec_children.c ft_split.c
BONUS = pipex_bonus.c pipex_utils.c exec_children.c ft_split.c
	  
FLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

bonus: fclean
	$(CC) -o $(NAME) $(BONUS)

re: fclean all