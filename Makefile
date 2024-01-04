NAME = push_swap

NAME_BONUS = checker

PUSH_SWAP = push_swap.a

PUSH_SWAP_BONUS = checker.a

FILES = src/push_swap.c\
src/check_num.c\
src/stacks.c\
src/index.c\
src/moves.c\
src/moves2.c\
src/moves3.c\
src/algorithm.c\
src/costs.c\
src/algorithm_utils.c

OBJECTS = $(FILES:.c=.o)

FILES_BONUS = srcb/checker.c

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a

LIB_SYS = -Iinclude -lglfw -L "/Users/etornay-/.brew/opt/glfw/lib/"

$(NAME):			$(OBJECTS) $(LIBFT)
						ar rcs $(PUSH_SWAP) $(OBJECTS)
						gcc $(FLAGS) $(PUSH_SWAP) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(NAME_BONUS):		$(OBJECTS_BONUS) $(OBJECTS) $(LIBFT)
						ar rcs $(PUSH_SWAP_BONUS) $(OBJECTS_BONUS) $(OBJECTS)
						gcc $(FLAGS) $(PUSH_SWAP_BONUS) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)

$(OBJECTS):			src/%.o : src/%.c
						gcc $(FLAGS) -c $< -o $@

$(OBJECTS_BONUS):	srcb/%.o : srcb/%.c
						gcc $(FLAGS) -c $< -o $@

$(LIBFT):
					make -s -C ./Libft

all:				$(NAME)

bonus:				$(NAME_BONUS)

clean:
					@ rm -f $(OBJECTS) $(OBJ_BONUS)
					@ make clean -s -C ./Libft

fclean:
					@ rm -f $(NAME) $(NAME_BONUS) $(OBJECTS) $(OBJECTS_BONUS) $(PUSH_SWAP) $(PUSH_SWAP_BONUS) $(LIBFT)
					@ make fclean -s -C ./Libft

re:					fclean all

.PHONY: all re clean fclean bonus