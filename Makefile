NAME		:=	cub3d
COMPILER	:=	cc
DEBUG_MODE	:=	
FLAGS		:= 	-Wall -Wextra -Werror

LIBS		:= 	./libft/libft.a
MLX			:=	./minilibx-linux
MLXLIB 	    := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit #codam_pc


#$(MLX)/libmlx42.a -I include -lglfw -L "/Users/dantehussain/.brew/opt/glfw/lib/" home_laptop
HEADERS		:= 	-I ./libft/ -I ./includes/ -I $(MLX)/include/
SRCS		:= 	main.c \
				utils.c \
				parser/parser.c \
				parser/map_opener.c \
				parser/content_sorter.c \
				parser/check_content.c \
				parser/map_checks.c \
				parser/map_checks_utils.c \
				parser/rgb_content_check.c \
				parser/rgb_content_utils.c \
				error_free/error.c \
				error_free/free.c \
			

SRCDIR 		:= 	./srcs
OBJDIR 		:= 	./objs
OBJS		:= 	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS		:= 	$(addprefix $(SRCDIR)/,$(SRCS))

# Colors #############################################
Black		= "\033[0;30m"		# Black
Red			= "\033[0;31m"		# Red
Green		= "\033[0;32m"		# Green
Yellow		= "\033[0;33m"		# Yellow
Blue		= "\033[0;34m"		# Blue
Purple		= "\033[0;35m"		# Purple
Cyan		= "\033[0;36m"		# Cyan
White		= "\033[0;37m"		# White
Text_Off	= "\033[0m"			# Text Style Off
Bold		= "\033[1m"			# Text Style Bold
######################################################

ifdef DEBUG
	COMPILER += -g -fsanitize=address
	LIBFT_DEBUG += DEBUG=1
	DEBUG_MODE += "(debug mode)"
endif

ifdef VALGRIND
	COMPILER += -g
	LIBFT_DEBUG += VALGRIND=1
	DEBUG_MODE += "(debug mode)"
endif

all: libs $(NAME)

libs:
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux DEBUG=1

$(NAME): $(OBJS)
	@$(MAKE) -C libft $(LIBFT_DEBUG) 
	@$(COMPILER) $^ $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(@D) 
	@$(COMPILER) $(FLAGS) $(HEADERS) -c $< -o $@

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

re:	fclean all

.PHONY:	all, clean, fclean, re