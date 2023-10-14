NAME          = so_long
INCLUDES      = include/
SRC_DIR       = src/
OBJ_DIR       = obj/

MLX_DIR	      = minilibx-linux/
MLX_LIB       = $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS     = -Lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR     = libft/
LIBFT_LIB     = $(LIBFT_DIR)libft.a

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_FILES     = so_long check_map check_map_utils render events moves

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE     = .cache_exists

#####

all:			$(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
					@make -C $(MLX_DIR)
					@echo "mlx lib compiled!"

$(LIBFT_LIB):
					@make -C $(LIBFT_DIR)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
					@echo "so_long compiled!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@echo "so_long object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "so_long executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for so_long!"

.PHONY:			all clean fclean re