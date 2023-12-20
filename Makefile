# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 17:33:31 by        #+#    #+#              #
#    Updated: 2023/12/04 12:08:33 by       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------
#VARIABLES

NAME 	:= cub3d
SRC 	:= main.c \
				utils.c \
				placing_images.c \
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

SUBDIR	:= srcs
OBJDIR 	:= ./objs
SRCS	:= $(addprefix $(SUBDIR),$(SRC))
OBJS	:= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))
LIBFT_A	:= libft/libft.a
MLX42_A	:= minilibx-linux/libmlx42.a
CMP		:= gcc
FLAGS 	:= -Werror -Wall -Wextra -g -fsanitize=address -I lib -Iinclude -ldl -lglfw -pthread -lm
HEADERS	:= 	-I libft/libft.h -I includes/cub3d.h -I $(MLX)/include/


all	: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A) $(MLX42_A) includes/cub3d.h
		@$(CC) $(FLAGS) $(HEADERS) $(OBJS) $(LIBFT_A) $(MLX42_A) -o $(NAME)

$(OBJDIR)/%.o: $(SUBDIR)/%.c | $(OBJDIR)
		@mkdir -p $(@D)
		$(CMP) -c $(FLAGS) -o $@ $<

$(OBJDIR):
	@mkdir $@

$(LIBFT_A) :
		@echo "$(BLUE)Building libft library...$(RESET)\n"
		@make -C /libft

$(MLX42_A) :
		(cd ./minilibx-linux && cmake -B build)
		(cd ./minilibx-linux && cmake --build build -j4)

clean :
		@rm -f $(OBJS) ./libft/libft.a

fclean :
		@rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY : clean fclean re hardclean