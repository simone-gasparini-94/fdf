CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror
INCS		=	-Iinc										\
				-Ilibft/inc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	events.c									\
				get_map.c									\
				get_projection.c							\
				get_viewport.c								\
				main.c										\
				render.c									\
				utils.c
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBFT		=	-Llibft -lft
MLX			=	-lX11 -lXext -lmlx
NAME		=	fdf

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

