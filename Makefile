OBJS = src/so_long.o src/so_long_utilse.o\
		src/read_file.o src/ft_split.o src/check_map.o\
		src/ft_putnbr.o src/close.o

BONUS_OBJS = bonus/src/so_long_bonus.o bonus/src/so_long_utilse_bonus.o\
			bonus/src/read_file_bonus.o bonus/src/ft_split_bonus.o bonus/src/check_map_bonus.o\
			bonus/src/ft_itoa_bonus.o bonus/src/close_bonus.o bonus/src/animation_bonus.o

NAME = so_long
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	cc $(FLAGS) $(BONUS_OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all $(NAME) clean fclean re bonus