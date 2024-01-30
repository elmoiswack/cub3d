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
	int		start_pos_x;
	int		start_pos_y;
	char	start_direction;
} t_parser;

typedef struct s_raycaster
{
	double		camera_x;
	double		direction_x;
	double		direction_y;
	double		distance_x;
	double		distance_y;
	double		delta_distance_x;
	double		delta_distance_y;
	double		map_x;
	double		map_y;
	double		perp_wall_dist;
	double		plane_x;
	double		plane_y;
	double		player_pos_x;
	double		player_pos_y;
	double		raydir_x;
	double		raydir_y;
	double 		relative_wall_x;
	double 		relative_wall_y;
	double		side_distance_x;
	double		side_distance_y;
	double		wall_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			texture_x;
	int			texture_y;
	int			side;
	int			step_x;
	int			step_y;
	char		start_direction;
} t_raycaster;
typedef struct s_gamestruct t_gamestruct;

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
	t_gamestruct *game;
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
	double		rots_speed;
	double		move_speed;
	double		frame_time;
	char		**map;
	mlx_t		*mlx;
	t_raycaster *player;
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
void	basic_raycaster(t_gamestruct *game);

void	start_game(t_gamestruct *game, t_raycaster *player);

void	set_vars_player(t_raycaster *player);

uint32_t	transfer_colour(int r, int g, int b);

//////////////PARSER///////////////////////////////////////////////////////////////////////////////////////////

		//parser.c
t_parser	*parser(t_parser *parser_s, char *argv[]);
int			transfer_rgb_to_int(char *rgb);
uint32_t		transfer_colour(int r, int g, int b);
t_parser	*parser_checks(t_parser *parser_s);

		//map_opener.c
int			check_argv(char **argv);
int			how_many_lines(int fd);
char		**get_content_into_array(char **array, int fd, int count);
char		**get_content_map(int fd, char *argv[]);
t_parser	*get_info_map(t_parser *parser_s, char *argv[]);

		//map_checks.c
int			border_check(char **map);
int			check_char_map(char	**map);
void		get_start_pos(char **map, int *x, int *y, char *start_derection);
int			check_howmany_start(char **map);

		//map_checks_utils.c
int			is_whitespace(char c);
int			valid_char(char c);
int			skip_whitespaces(char *line, int index);
int			get_start_map(t_parser *parser_s);

		//rgb_content_checks.c
int			check_range_rgb(char *line);
int			get_single_rgb_value(char *line, int index, int begin);
int			range_compare(char *line);
int			check_chars_rgb(char *line);

		//rgb_content_utils.c
int			overflow_check(char *line);
int			ammount_input_rgb(char *line);

		//content_sorter.c
t_parser	*sort_content(t_parser *parser_s);
t_parser	*get_map(t_parser *parser_s , int index);
t_parser	*get_textures_rgb_path(t_parser *parser_s);
char		*line_into_struct(char	*line, t_parser *parser_s);

		//check_content.c
int			floodfill(char	**map, int start_x, int start_y);
int			map_checker(char **map, t_parser *parser_s);
int			rgb_checks(char *line);
int			alpha_in_texture(char *line);
int			are_there_empty_inputs(t_parser *parser_s);

//////////////MINIMAP///////////////////////////////////////////////////////////////////////////////////////////
		//initialize.c
void	set_vars_minimap(t_gamestruct *game);
void	calculate_mm_scaler(t_minimap *mini);
void	calculate_fm_scaler(t_minimap *mini);

		//minimap.c
void	mm_place_content(char **array, t_minimap *mini);
char	**fill_array_mm(char **array, char **map, int player_x, int player_y);
void	allocate_images_mm(t_minimap *mini);
void	create_minimap(t_minimap *minimap);

		//map_utils.c
int		get_size_biggest_line(char **map);
char	**allocate_array_mm(t_minimap *mini);
bool	out_of_map_x(char **map, int player_x, int player_y, int x);
bool	out_of_map_y(char **map, int player_y, int y);

		//mm_creating.c
void	mm_make_border(t_minimap *mini);
void	mm_make_walls(t_minimap *mini);
void	mm_make_floors(t_minimap *mini);
void	mm_make_player(t_minimap *mini);

		//mm_placing.c
void	mm_place_player(t_minimap *mini, int x, int y);
void	mm_place_floors(t_minimap *mini, int x, int y);
void	mm_place_walls(t_minimap *mini, int x, int y);
void	mm_place_border(t_minimap *mini, int x, int y);

		//fullmap.c
void	create_fullmap(t_minimap *mini);
void 	place_fullmap(t_minimap *mini);
void	allocate_fullmap(t_minimap *mini);

		//fm_creating.c
void	fullmap_make_walls(t_minimap *mini);
void	fullmap_make_floors(t_minimap *mini);
void	fullmap_make_player(t_minimap *mini);
void	fullmap_make_background(t_minimap *mini);

		//fm_placing.c
void	fullmap_place_walls(t_minimap *mini);
void	fullmap_place_floors(t_minimap *mini);
void	fullmap_place_background(t_minimap *mini);
void	fullmap_place_player(t_minimap *mini);

		//enable_disable.c
void	enable_minimap(t_minimap *mini);
void	disable_minimap(t_minimap *mini);
void	disable_fullmap(t_minimap *mini);
void	enable_fullmap(t_minimap *mini);



//convert_data.c
t_gamestruct	*convert_data(t_parser *parser_s, t_gamestruct *gamestruct, t_raycaster *player);
t_gamestruct	*getting_images(t_parser *parser, t_gamestruct *game);
t_gamestruct	*texture_to_images(t_gamestruct *game, t_parser *parser);



//////////////FREE AND ERROR/////////////////////////////////////////////////////////////////////////////////////

	//free.c
void	free_2d_array(char	**array);
void	free_minimap_struct(t_minimap *mini);
void	free_game_struct(t_gamestruct *game);
void	free_parser_struct(t_parser *parser_s);


	//mlx_free.c
void	delete_game_textures(t_gamestruct *game);
void	delete_game_images(t_gamestruct *game);
void	delete_fullmap(t_minimap *minimap);
void	delete_minimap(t_minimap *mini);

	//error.c
void		error_parser( t_parser *parser_s, const char *str);
void		error_convert(t_parser *parser, t_gamestruct *game, const char *str);
void		error_game(t_gamestruct *game, const char *str);

#endif