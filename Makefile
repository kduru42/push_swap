NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCE = ./src/ps_operations.c ./src/push_swap_utils.c ./src/push_swap.c ./src/ps_operations_pt2.c ./src/ps_operations_pt3.c ./src/find_some_nums.c \
./src/case_less_than_ten.c ./src/sort_more_nums.c ./src/check_errors.c ./src/last.c 


MAIN = main.o

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJECT)
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJECT) $(MAIN) ./ft_printf/libftprintf.a -o $(NAME)

clean:
	$(RM) $(OBJECT) $(MAIN)
	@make -C ./ft_printf clean

fclean: clean
	$(RM) $(NAME)
	@make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re