NAME		:=	cub3d
COMPILER	:=	cc
DEBUG_MODE	:=	
FLAGS		:= 	-Wall -Wextra -Werror

LIBS		:= 	./libft/libft.a
MLX			:=	./minilibx-linux
MLXLIB		:= $(MLX)/build/libmlx42.a
HEADERS		:= 	-I libft -I includes/ -I $(MLX)/include/
SRCS		:= 	main.c \
				parser/parser.c \
				parser/map_opener.c \
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

all: $(NAME)

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

fclean:	clean
	@rm -f $(NAME) 
	@$(MAKE) -C libft fclean

re:	fclean all

.PHONY:	all, clean, fclean, re