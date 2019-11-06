NAME := wolf3d

SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/
LIB_DIR := libft/

SRC	=	main.c parsing.c \
		raycasting.c \
		rendering.c \
		hooks.c \
		move_and_rotate.c \
		init.c \
		floor_casting.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIB_DIR)libft.a
LIBFT_F := -lft -L $(LIB_DIR)

FRAME_DIR = -F frameworks/

INC = -I $(INC_DIR) \
	  -I ./frameworks/SDL2.framework/Headers/ \
	  -I ./frameworks/SDL2_image.framework/Headers \
	  -I $(LIB_DIR) \
	  $(FRAME_DIR)

FRAME = $(FRAME_DIR) \
		-rpath frameworks/ \
		-framework OpenGL -framework AppKit \
		-framework SDL2 \
		-framework SDL2_image

LINK_F := $(LIBFT_F)
GCC_F := -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(GCC_F) $(OBJ) $(LINK_F) -o $(NAME) $(INC) $(FRAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJ_DIR)%.o: %.c
	gcc $(GCC_F) -c $< -o $@ $(INC)

clean:
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all

vpath %.c $(SRC_DIR)
