#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/include/MLX42/MLX42.h"

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
	uint32_t rgb_floor_int;
	uint32_t rgb_ceiling_int;
	int		start_posx;
	int		start_posy;
	char	start_direction;
} t_parser;

typedef struct s_playerdirections
{
	char		start_direction;
	double		player_posx;
	double		player_posy;
	double		directionx;
	double		directiony;
	double		plane_x;
	double		plane_y;
	double		camerax;
	double		raydir_x;
	double		raydir_y;
} t_playerinfo;

typedef struct s_minimap
{
	bool		fullmap_enabled;
	bool		minimap_enabled;
	int			mm_scaler;
	int			fm_scaler;
	int			fm_offset;
	char		**file_map;
	double		player_x;
	double		player_y;
	mlx_t		*mlx;
	mlx_image_t	*screen_border;
	mlx_image_t *screen_wall;
	mlx_image_t *screen_floor;
	mlx_image_t *screen_player;
	mlx_image_t	*fullm_background;
	mlx_image_t *fullm_wall;
	mlx_image_t *fullm_floor;
	mlx_image_t *fullm_player;
} t_minimap;

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
	mlx_image_t *raycaster_img;
	uint32_t	floor_rgb;
	uint32_t	ceiling_rgb;
	char		**map;
	mlx_t		*mlx;
	t_playerinfo *player;
	t_minimap	*minimap;
} t_gamestruct;

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define MINIMAP_WIDTH (SCREEN_WIDTH / 5)
# define MINIMAP_HEIGHT (SCREEN_HEIGHT / 5)

	//MAIN.C
int			main(int argc, char *argv[]);
	//utils.c
int			get_max_2d(char **array);
char		**copy_2d_array(char **array);

	//raycaster.c
void	basic_raycaster(t_gamestruct *game, t_playerinfo *player);

void	start_game(t_gamestruct *game, t_playerinfo *player);

int	transfer_colour(int r, int g, int b);


//////////////MINIMAP///////////////////////////////////////////////////////////////////////////////////////////

	//initialize.c
void	set_vars_minimap(t_gamestruct *game);
void	calculate_fm_scaler(t_minimap *mini);
int		get_size_biggest_line(char **map);

	//minimap.c
void	create_minimap(t_minimap *minimap);
void	allocate_images(t_minimap *mini);
void	enable_minimap(t_minimap *mini);
void	disable_minimap(t_minimap *mini);

	//creating.c
void	mm_make_walls(t_minimap *mini);
void	mm_make_floors(t_minimap *mini);
void	mm_make_player(t_minimap *mini);
void	mm_make_border(t_minimap *mini);

	//placing.c
void	mm_place_border(t_minimap *mini, int x, int y);
void	mm_place_walls(t_minimap *mini, int x, int y);
void	mm_place_floors(t_minimap *mini, int x, int y);
void	mm_place_player(t_minimap *mini, int x, int y);

	//fullmap.c
void	allocate_fullmap(t_minimap *mini);
void 	place_fullmap(t_minimap *mini);
void	disable_fullmap(t_minimap *mini);
void	enable_fullmap(t_minimap *mini);
void	create_fullmap(t_minimap *mini);

	//fm_creating.c
void	fullmap_make_player(t_minimap *mini);
void	fullmap_make_floors(t_minimap *mini);
void	fullmap_make_walls(t_minimap *mini);
void	fullmap_make_background(t_minimap *mini);

	//fm_placing.c
void	fullmap_place_player(t_minimap *mini);
void	fullmap_place_floors(t_minimap *mini);
void	fullmap_place_walls(t_minimap *mini);
void	fullmap_place_background(t_minimap *mini);

//////////////PARSER///////////////////////////////////////////////////////////////////////////////////////////

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
void		convert_rgb_to_hex(t_gamestruct *game);


//convert_data.c
t_gamestruct	*convert_data(t_parser *parser_s, t_gamestruct *gamestruct, t_playerinfo *player);
t_gamestruct	*getting_images(t_parser *parser, t_gamestruct *game);
t_gamestruct	*texture_to_images(t_gamestruct *game, t_parser *parser);



//////////////FREE AND ERROR/////////////////////////////////////////////////////////////////////////////////////

	//free.c
void		free_parser_struct(t_parser *parser_s);
void		free_game_struct(t_gamestruct *gamestruct);
void		free_2d_array(char	**array);


	//mlx_free.c
void		delete_textures(t_gamestruct *game);
void		delete_fullmap(t_minimap *minimap);
void		delete_minimap(t_minimap *mini);

	//error.c
void		error_parser( t_parser *parser_s, const char *str);
void		error_convert(t_parser *parser, t_gamestruct *game, const char *str);
void		error_game(t_gamestruct *game, const char *str);

#endif