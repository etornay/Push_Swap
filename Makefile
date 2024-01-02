NAME = push_swap

PUSHSWAP = push_swap.a

FILES = src/push_swap.c\
src/checker.c\
src/stacks.c\
src/index.c\
src/moves.c\
src/moves2.c\
src/moves3.c\
src/algorithm.c\
src/costs.c\
src/algorithm_utils.c\

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a

LIB_SYS = -Iinclude -lglfw -L "/Users/etornay-/.brew/opt/glfw/lib/"

$(NAME):			$(OBJECTS) $(LIBFT)
						ar rcs $(PUSHSWAP) $(OBJECTS)
						gcc $(FLAGS) $(PUSHSWAP) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJECTS):	src/%.o : src/%.c
						gcc $(FLAGS) -c $< -o $@

$(LIBFT):
					make -s -C ./Libft

all:				$(NAME)

clean:
					@ rm -f $(OBJECTS)
					@ make clean -s -C ./Libft

fclean:
					@ rm -f $(NAME) $(OBJECTS) $(PUSHSWAP) $(LIBFT)
					@ make fclean -s -C ./Libft

re:					fclean all

.PHONY: all re clean fclean