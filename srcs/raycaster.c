#include "../includes/cub3d.h"
#include <math.h>

//With this function the goal is having a different player view when the user select a different
//spawn direction.
void	set_vars_player(t_raycaster *player)
{
	if (player->start_direction == 'N')
	{
		player->direction_x = -1;
		player->direction_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->start_direction == 'S')
	{
		player->direction_x = 1;
		player->direction_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->start_direction == 'E')
	{
		player->direction_x = 0;
		player->direction_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->start_direction == 'W')
	{
		player->direction_x = 0;
		player->direction_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
}

static uint32_t get_pixel_from_texture(mlx_texture_t *texture, double x_mult, double y_mult)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t b;
	uint8_t a;
	int int_x_mult = (int) x_mult;
	int int_y_mult = (int) y_mult;

	r = texture->pixels[(int_y_mult * texture->width + int_x_mult) * texture->bytes_per_pixel];
	g = texture->pixels[(int_y_mult * texture->width + int_x_mult) * texture->bytes_per_pixel + 1];
	b = texture->pixels[(int_y_mult * texture->width + int_x_mult) * texture->bytes_per_pixel + 2];
	a = texture->pixels[(int_y_mult * texture->width + int_x_mult) * texture->bytes_per_pixel + 3];
	return (transfer_colour_texture(r, g, b, a));
}

mlx_texture_t	*put_texture(t_gamestruct *game, mlx_texture_t *current_texture)
{
	if (game->player->side == 1 && (game->player->map_y - 1 > 0))
		current_texture = game->north_textu;
	else if (game->player->side == 1 && (game->player->map_y + 1 < get_max_2d(game->map)))
		current_texture = game->south_textu;
	else if (game->player->side == 0  &&  (game->player->map_x - 1 > 0))
		current_texture = game->west_textu;
	else if (game->player->side == 0 && (game->player->map_x + 1 < ft_strlen(game->map[(int)game->player->map_y])))
		current_texture = game->east_textu;
	return (current_texture);
}

//calculation of the ray from one x or y side
void	ray_length(t_gamestruct *game)
{
	if (game->player->raydir_x == 0)
		game->player->delta_distance_x = 1e30;
	else 
		game->player->delta_distance_x = fabs((float)1 / game->player->raydir_x);
	if (game->player->raydir_y == 0)
		game->player->delta_distance_y = 1e30;
	else
		game->player->delta_distance_y = fabs((float)1 / game->player->raydir_y);
}

//initialize the side and the side_dist
void	side_side_dist_init(t_gamestruct *game)
{
	if(game->player->raydir_x < 0)
    {
       	game->player->step_x = -1;
        game->player->side_distance_x = (game->player->player_pos_x - game->player->map_x) * game->player->delta_distance_x;
    }
  	else
	{
      	game->player->step_x = 1;
      	game->player->side_distance_x = (game->player->map_x + 1.0 - game->player->player_pos_x) * game->player->delta_distance_x;
    }
    if (game->player->raydir_y < 0)
    {
        game->player->step_y = -1;
        game->player->side_distance_y = (game->player->player_pos_y - game->player->map_y) * game->player->delta_distance_y;
    }
    else
    {
       game->player->step_y = 1;
       game->player->side_distance_y = (game->player->map_y + 1.0 - game->player->player_pos_y) * game->player->delta_distance_y;
    }
}

//performing DDA and check if the ray hit a wall
void	hit_wall_check(t_gamestruct *game)
{
	int	hit;

	hit = 0;
	while(hit == 0)
	{
		//jump to the next map square
		if(game->player->side_distance_x < game->player->side_distance_y)
		{
			game->player->side_distance_x += game->player->delta_distance_x;
			game->player->map_x += game->player->step_x;
			game->player->side = 0;
		}
		else
		{
			game->player->side_distance_y += game->player->delta_distance_y;
			game->player->map_y += game->player->step_y;
			game->player->side = 1;
		}
		if(game->map[(int)game->player->map_y][(int)game->player->map_x] == '1')
			hit = 1;
	}
}

//calculate value of wall_x and calculate distance of perpendicular ray
void	wall_x_perp_wall_dist_calculation(t_gamestruct *game)
{
	if (game->player->side == 0)
	{
		game->player->perp_wall_dist = (game->player->side_distance_x - game->player->delta_distance_x);
		game->player->wall_x = (game->player->raydir_y * game->player->perp_wall_dist) + game->player->player_pos_y;
	}
	else
	{
		game->player->perp_wall_dist = (game->player->side_distance_y - game->player->delta_distance_y);
		game->player->wall_x = (game->player->raydir_x * game->player->perp_wall_dist) + game->player->player_pos_x;
	}
	game->player->wall_x -= floor(game->player->wall_x);
}

//x cordinate on the texture
void	texture_x_calculation(t_gamestruct *game, mlx_texture_t *texture)
{
	game->player->texture_x = (int)(game->player->wall_x * (double)texture->width);
	if (game->player->side == 0 && game->player->raydir_x > 0)
		game->player->texture_x = texture->width - game->player->texture_x - 1;
	if (game->player->side == 1 && game->player->raydir_y < 0)
		game->player->texture_x = texture->width - game->player->texture_x - 1;
}

void	calculation_lowest_highest_pixel(t_gamestruct *game)
{
	game->player->line_height = (int)(SCREEN_HEIGHT / game->player->perp_wall_dist);
	game->player->draw_start = -game->player->line_height / 2 + SCREEN_HEIGHT / 2;
	game->player->relative_wall_x = game->player->wall_x - (int) game->player->wall_x;
	if(game->player->draw_start < 0)
		game->player->draw_start = 0;
	game->player->draw_end = game->player->line_height / 2 + SCREEN_HEIGHT / 2;
	if(game->player->draw_end >= SCREEN_HEIGHT) 
		game->player->draw_end = SCREEN_HEIGHT - 1;
}

void	draw_ceiling(t_gamestruct *game, int x)
{
	int	index;

	index = 0;
	if (game->player->draw_start > 0)
	{
		while (index < game->player->draw_start)
		{
			mlx_put_pixel(game->raycaster_img, x, index, game->ceiling_rgb);
			index++;
		}
	}
}

void 	draw_wall(t_gamestruct *game, mlx_texture_t *texture, int x)
{
	uint32_t	text_color;
	double		texture_pos;
	double		step;

	game->player->line_height = (game->player->draw_end - game->player->draw_start);
	step = 1.0 * texture->height / game->player->line_height;
	texture_pos = (game->player->draw_start - SCREEN_HEIGHT / 2 + game->player->line_height / 2) * step;
	while (game->player->draw_start < game->player->draw_end)
	{
		game->player->texture_y = (int)texture_pos & (texture->height - 1);
		texture_pos += step;
		text_color = get_pixel_from_texture(texture, game->player->texture_x, game->player->texture_y);
		mlx_put_pixel(game->raycaster_img, x, game->player->draw_start, text_color);
		game->player->draw_start++;
	}
}

void	draw_floor(t_gamestruct *game, int x)
{
	if (game->player->draw_end < SCREEN_HEIGHT - 1)
	{
		while (game->player->draw_end < SCREEN_HEIGHT - 1)
		{
			mlx_put_pixel(game->raycaster_img, x, game->player->draw_end, game->floor_rgb);
			game->player->draw_end++;
		}
	}
}

//fare un buffer che ha come grandezza altezza e larghezza dello schermo dove lo coloreremo
void	basic_raycaster(t_gamestruct	*game)
{
	mlx_texture_t	*current_texture;
	int				i;

	current_texture = NULL;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		game->player->camera_x = 2 * (i / (double)SCREEN_WIDTH) - 1;
		game->player->raydir_x = game->player->direction_x + game->player->plane_x * game->player->camera_x;
		game->player->raydir_y = game->player->direction_y + game->player->plane_y * game->player->camera_x;
		game->player->map_x = game->player->player_pos_x - 0.5; //if i want the camera to be centered
		game->player->map_y = game->player->player_pos_y - 0.5; //if i want the camera to be centered 
		ray_length(game);
		side_side_dist_init(game);
		hit_wall_check(game);
		wall_x_perp_wall_dist_calculation(game);
		calculation_lowest_highest_pixel(game);
		current_texture = put_texture(game, current_texture);
		texture_x_calculation(game, current_texture);
		draw_ceiling(game, i);
		draw_wall(game, current_texture, i);
		draw_floor(game, i);
		i++;
	}
	return ;
}
