#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
//#include "../minilibx-linux/mlx_int.h"
//#include "../minilibx-linux/mlx.h"

typedef struct s_parser
{
	char	**full_file;
	char	**map;
	char	*n_texture;
	char	*e_texture;
	char	*s_texture;
	char	*w_texture;
	char	*rgb_floor;
	char	*rgb_ceiling;

} t_parser;


	//PARSER

	//parser.c
t_parser *parser(t_parser *parser_s, char *argv[]);

	//map_opener.c
t_parser *get_info_map(t_parser *parser_s, char *argv[]);
int			check_argv(char **agrv);

	//content_sorter.c
t_parser *sort_content(t_parser *parser_s);

	//free.c
void	free_parser_struct(t_parser *parser_s);
void	free_2d_array(char	**array);

	//error.c
void	error_parser( t_parser *parser_s, const char *str);

#endif