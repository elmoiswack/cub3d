NAME 	:= cub3d

SRC 	:= main.c \
				utils.c \
				game.c \
				movement.c \
				loop_hooks.c \
				setup_game.c \
				mouse_move.c \
				raycaster/raycaster.c \
				raycaster/calculations.c \
				raycaster/draw.c \
				minimap/initialize.c \
				minimap/minimap.c \
				minimap/fullmap.c \
				minimap/fm_creating.c \
				minimap/fm_placing.c \
				minimap/enable_disable.c \
				minimap/map_utils.c \
				parser/parser.c \
				parser/file_opener.c \
				parser/content_sorter.c \
				parser/check_content.c \
				parser/map_checks.c \
				parser/map_checks_utils.c \
				parser/map_checks_fts.c \
				parser/rgb_content_check.c \
				parser/rgb_content_utils.c \
				convert_data.c \
				error_free/error.c \
				error_free/free.c \
				error_free/mlx_free.c \

SUBDIR	:= ./srcs
OBJDIR 	:= ./objs
SRCS	:= $(addprefix $(SUBDIR),$(SRC))
OBJS	:= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))


LIBFTLIB := ./libft
LIBFT_A	:= ./libft/libft.a
MLXLIB	:= ./minilibx-linux
MLX42_A	:= ./minilibx-linux/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
LIBS	:= $(LIBFT_A) $(MLX42_A)

CMP		:= gcc 
FLAGS 	:= -Wall -Wextra -Ofast -march=native -mtune=native
HEADER	:= -I ./includes/
HEADERS	:= -I ./libft/ -I $(MLX)/include/

ifdef DEBUG
	CMP += -g3 -fsanitize=address 
endif

ifdef VALGRIND
	CMP += -g
endif

all: libmlx $(NAME)

libmlx:
	@cmake $(MLXLIB) -B $(MLXLIB)/build && make -C $(MLXLIB)/build -j4
	@$(MAKE) -C libft

$(NAME) : $(OBJS)
		$(CMP) $^ $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SUBDIR)/%.c
		mkdir -p $(@D)
		$(CMP) $(FLAGS) -o $@ -c $<

clean:	
	@rm -rf $(MLXLIB)/build
	@rm -rf $(OBJDIR)
	@$(MAKE) -C libft clean

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(MLXLIB)/build
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
