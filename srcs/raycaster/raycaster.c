/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:14:41 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:14:42 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

//With this function the goal is having a 
//different player view when 
//the user select a different
//spawn direction.

void	set_vars_player_e_w(t_raycaster *player)
{
	if (player->start_direction == 'E')
	{
		player->direction_x = 1;
		player->direction_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->start_direction == 'W')
	{
		player->direction_x = -1;
		player->direction_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

void	set_vars_player(t_raycaster *player)
{
	if (player->start_direction == 'N')
	{
		player->direction_x = 0;
		player->direction_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->start_direction == 'S')
	{
		player->direction_x = 0;
		player->direction_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		set_vars_player_e_w(player);
}

//calculation of the ray from one x or y side
void	ray_length(t_gamestruct *game)
{
	if (game->player->raydir_x == 0)
		game->player->delta_distance_x = 1e30;
	else
		game->player->delta_distance_x = \
			fabs((float)1 / game->player->raydir_x);
	if (game->player->raydir_y == 0)
		game->player->delta_distance_y = 1e30;
	else
		game->player->delta_distance_y = \
			fabs((float)1 / game->player->raydir_y);
}

//initialize the side and the side_dist
void	side_side_dist_init(t_gamestruct *game)
{
	if (game->player->raydir_x < 0)
	{
		game->player->step_x = -1;
		game->player->side_distance_x = (game->player->player_pos_x - \
			game->player->map_x) * game->player->delta_distance_x;
	}
	else
	{
		game->player->step_x = 1;
		game->player->side_distance_x = (game->player->map_x + 1.0 - \
			game->player->player_pos_x) * game->player->delta_distance_x;
	}
	if (game->player->raydir_y < 0)
	{
		game->player->step_y = -1;
		game->player->side_distance_y = (game->player->player_pos_y - \
			game->player->map_y) * game->player->delta_distance_y;
	}
	else
	{
		game->player->step_y = 1;
		game->player->side_distance_y = (game->player->map_y + 1.0 - \
			game->player->player_pos_y) * game->player->delta_distance_y;
	}
}

void	raycaster(t_gamestruct *game, int i)
{
	mlx_texture_t	*current_texture;

	current_texture = NULL;
	i = 0;
	draw_ceiling_floor(game);
	while (i < SCREEN_WIDTH)
	{
		game->player->camera_x = 2 * (i / (double)SCREEN_WIDTH) - 1;
		game->player->raydir_x = game->player->direction_x + \
			game->player->plane_x * game->player->camera_x;
		game->player->raydir_y = game->player->direction_y + \
			game->player->plane_y * game->player->camera_x;
		game->player->map_x = (int)game->player->player_pos_x;
		game->player->map_y = (int)game->player->player_pos_y;
		ray_length(game);
		side_side_dist_init(game);
		hit_wall_check(game);
		wall_x_perp_wall_dist_calculation(game);
		calculation_lowest_highest_pixel(game);
		current_texture = put_texture(game, current_texture);
		texture_x_calculation(game, current_texture);
		draw_wall(game, current_texture, i);
		i++;
	}
	return ;
}
