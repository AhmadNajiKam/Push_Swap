NAME := push_swap
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRCS := ./utils/ft_dprintf/ft_dprintf.c ./utils/ft_dprintf/ft_dputchar.c \
				./utils/ft_dprintf/ft_dputdouble.c ./utils/ft_dprintf/ft_dputnbr.c \
				./utils/ft_dprintf/ft_dputstr.c ./utils/ft_isdigit.c ./utils/ft_lstnew.c \
				./utils/ft_strcmp.c ./utils/ft_strlen.c ./utils/handle_numbers.c \
				./utils/parsing.c ./utils/shared_utils.c \
				./utils/stack_utils.c ./bench/bench.c ./mode/mode_handling.c \
				./operations/push_swap_ops.c ./operations/rotate_ops.c \
				./algorithms/adaptive/adaptive.c ./algorithms/complex/complex.c\
				./algorithms/medium/medium.c ./algorithms/simple/simple.c \
				./algorithms/general_utils.c ./error_handling/check_errors.c \
				./error_handling/error_utils.c ./main.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all
.PHONY: all clean fclean re
