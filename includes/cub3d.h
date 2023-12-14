#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../minilibx-linux/include/MLX42/MLX42.h"
#include "../minilibx-linux/include/MLX42/MLX42_Int.h"
#include "../minilibx-linux/include/MLX42/MLX42_Input.h"

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
	int		start_posx;
	int		start_posy;
	char	start_direction;
} t_parser;

typedef struct s_gamestruct
{
	mlx_texture_t *north_textu;
	mlx_texture_t *south_textu;
	mlx_texture_t *west_textu;
	mlx_texture_t *east_textu;
	mlx_image_t *north;
	mlx_image_t	*south;
	mlx_image_t *west;
	mlx_image_t *east;
	char		*floor_rgb;
	char		*ceiling_rgb;
	char		**map;
	int			start_x;
	int			start_y;
	char		start_direction;
	mlx_t		*mlx;
} t_gamestruct;

	//MAIN.C
int			main(int argc, char *argv[]);
	//utils.c
int			get_max_2d(char **array);
char		**copy_2d_array(char **array);


	//PARSER

	//parser.c
t_parser	*parser(t_parser *parser_s, char *argv[]);
t_parser	*parser_checks(t_parser *parser_s);

	//map_opener.c
t_parser	*get_info_map(t_parser *parser_s, char *argv[]);
int			check_argv(char **agrv);
char		**get_content_map(int fd, char *argv[]);
char		**get_content_into_array(char **array, int fd, int count);
int			get_content_into_line(int fd);

	//content_sorter.c
t_parser	*sort_content(t_parser *parser_s);
t_parser	*get_map(t_parser *parser_s , int index);
int			get_start_map(t_parser *parser_s);
t_parser	*get_textures_rgb_path(t_parser *parser_s);
char		*line_into_struct(char	*line, t_parser *parser_s);

	//check_content.c
int			are_there_empty_inputs(t_parser *parser_s);
int			map_checker(char **map, t_parser *parser_s);
int			floodfill(char	**map, int start_x, int start_y);

	//map_checks.c
int			border_check(char **map);
int			check_char_map(char	**map);
void		get_start_pos(char **map, int *x, int *y, char *start_derection);
int			check_howmany_start(char **map);

	//map_checks_utils.c
int			skip_whitespaces(char *line, int index);
int			valid_char(char c);
int			is_whitespace(char c);

	//rgb_content_check.c
int			alpha_in_texture(char *line);
int			check_chars_rgb(char *line);
int			range_compare(char *line);
int			check_range_rgb(char *line);

	//rgb_content_utils.c
int			overflow_check(char *line);
int			ammount_input_rgb(char *line);



//convert_data.c
t_gamestruct	*convert_data(t_parser *parser_s, t_gamestruct *gamestruct);


	//UTILS

	//free.c
void		free_parser_struct(t_parser *parser_s);
void		free_game_struct(t_gamestruct *gamestruct);
void		free_2d_array(char	**array);

	//error.c
void		error_parser( t_parser *parser_s, const char *str);
void		error_convert(t_parser *parser, t_gamestruct *game, const char *str);

#endif