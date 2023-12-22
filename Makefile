NAME 	:= cub3d

SRC 	:= main.c \
				utils.c \
				placing_images.c \
				raycaster.c \
				parser/parser.c \
				parser/map_opener.c \
				parser/content_sorter.c \
				parser/check_content.c \
				parser/map_checks.c \
				parser/map_checks_utils.c \
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

LIBFT_A	:= ./libft/libft.a
MLX42_A	:= ./minilibx-linux/libmlx42.a

CMP		:= gcc
FLAGS 	:= -Werror -Wall -Wextra
HEADERS	:= 	-I ./libft/-I includes/cub3d.h -I $(MLX)/include/ -I lib -Iinclude -ldl -lglfw -pthread -lm
LIBS	:= $(LIBFT_A) $(MLX42_A)

all	: $(NAME)

$(NAME) : $(OBJS)
		@make -C ./libft
		@make -C ./minilibx-linux
		@$(CMP) $^ $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SUBDIR)/%.c | $(OBJDIR)
		@mkdir -p $(@D)
		$(CMP) -c $(FLAGS) -o $@ $<

$(OBJDIR):
	@mkdir $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C libft clean
	@$(MAKE) -C minilibx-linux clean

fclean:	clean
	@rm -f $(NAME) 
	@$(MAKE) -C libft fclean
	@$(MAKE) -C minilibx-linux fclean

re : fclean all

.PHONY : all clean fclean re