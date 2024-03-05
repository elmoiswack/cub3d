/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:14:35 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:14:36 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

//calculate value of wall_x and calculate distance of perpendicular ray
void	wall_x_perp_wall_dist_calculation(t_gamestruct *game)
{
	if (game->player->side == 0)
	{
		game->player->perp_wall_dist = (game->player->side_distance_x - \
			game->player->delta_distance_x);
		game->player->wall_x = (game->player->raydir_y * \
			game->player->perp_wall_dist) + game->player->player_pos_y;
	}
	else
	{
		game->player->perp_wall_dist = (game->player->side_distance_y - \
			game->player->delta_distance_y);
		game->player->wall_x = (game->player->raydir_x * \
			game->player->perp_wall_dist) + game->player->player_pos_x;
	}
	game->player->wall_x -= floor(game->player->wall_x);
}

//x cordinate on the texture
void	texture_x_calculation(t_gamestruct *game, mlx_texture_t *texture)
{
	game->player->texture_x = (int)(game->player->wall_x * \
		(double)texture->width);
	if (game->player->side == 0 && game->player->raydir_x > 0)
		game->player->texture_x = texture->width - game->player->texture_x - 1;
	if (game->player->side == 1 && game->player->raydir_y < 0)
		game->player->texture_x = texture->width - game->player->texture_x - 1;
}

void	calculation_lowest_highest_pixel(t_gamestruct *game)
{
	game->player->line_height = (int)(SCREEN_HEIGHT / \
		game->player->perp_wall_dist);
	game->player->draw_start = -game->player->line_height / \
		2 + SCREEN_HEIGHT / 2;
	if (game->player->draw_start < 0)
		game->player->draw_start = 0;
	game->player->draw_end = game->player->line_height / \
		2 + SCREEN_HEIGHT / 2;
	if (game->player->draw_end >= SCREEN_HEIGHT)
		game->player->draw_end = SCREEN_HEIGHT - 1;
}

//performing DDA and check if the ray hit a wall
void	hit_wall_check(t_gamestruct *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->player->side_distance_x < game->player->side_distance_y)
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
		if (game->map[game->player->map_y][game->player->map_x] == '1')
			hit = 1;
	}
}
