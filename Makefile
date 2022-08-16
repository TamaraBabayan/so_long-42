NAME = so_long

BONUS = bonus_so_long

SRCS = $(shell find "./mandatory" -name "*.c")

BSRCS = $(shell find "./bonus" -name "*.c")

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDE = ./includes

LINKER = -L./libft -lft

.c.o : 
	@$(CC) $(FLAGS) -I$(INCLUDE) -Imlx -c $< -o $(<:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(FLAGS) -I$(INCLUDE) $(LINKER) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS) : $(BOBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(FLAGS) -I$(INCLUDE) $(LINKER) $(BOBJS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

clean : 
	@rm -f $(OBJS) $(BOBJS)
	@$(MAKE) clean -C ./libft

fclean : clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) fclean -C libft

re : fclean all

.PHONY: all clean re fclean
