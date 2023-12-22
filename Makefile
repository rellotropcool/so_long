NAME		=	so_long

CC		=	cc

FLAGS		=	-Wall -Wextra -Werror -g3

MLX_FLAGS	=	-lX11 -lXext

SRC		=	src/test.c \
			src/map_init.c \
			src/map_utils.c \
			src/map_check.c \
			src/key_hook.c \
			src/print_map.c \
			src/vars_gen.c \
			src/map_is_endable.c \
			src/map_check_utils.c

all:		$(NAME)

$(NAME):	$(SRC)
		@make -C mlx
		@cp mlx/libmlx.a ./
		@cp mlx/libmlx_Linux.a ./
		@$(CC) $(FLAGS) $(SRC) libmlx.a libmlx_Linux.a $(MLX_FLAGS) -o $(NAME)
		@echo Compiled

clean:
		@rm $(NAME)
		@rm libmlx.a libmlx_Linux.a
		@make clean -C mlx
		@echo Cleaned
			
fclean:		clean
			
re:		fclean all


.PHONY:		all clean fclean re
