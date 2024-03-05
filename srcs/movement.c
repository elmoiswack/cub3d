/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:15:01 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:15:03 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

int	player_hits_wall(t_gamestruct *game, int x, int y)
{
	return (game->map[y][x] == '1');
}

void	movement_forward(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = 0.15;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		new_pos_x = game->player->player_pos_x + \
			(game->player->direction_x * move_speed);
		new_pos_y = game->player->player_pos_y + \
			(game->player->direction_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x += \
				(game->player->direction_x * move_speed);
			game->player->player_pos_y += \
				(game->player->direction_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void	movement_backwards(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = 0.15;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		new_pos_x = game->player->player_pos_x - \
			(game->player->direction_x * move_speed);
		new_pos_y = game->player->player_pos_y - \
			(game->player->direction_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x -= \
				(game->player->direction_x * move_speed);
			game->player->player_pos_y -= \
				(game->player->direction_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void	movement_right(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = 0.15;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		new_pos_x = game->player->player_pos_x + \
			(game->player->plane_x * move_speed);
		new_pos_y = game->player->player_pos_y + \
			(game->player->plane_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x += (game->player->plane_x * move_speed);
			game->player->player_pos_y += (game->player->plane_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void	movement_left(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = 0.15;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		new_pos_x = game->player->player_pos_x - \
			(game->player->plane_x * move_speed);
		new_pos_y = game->player->player_pos_y - \
			(game->player->plane_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x -= (game->player->plane_x * move_speed);
			game->player->player_pos_y -= (game->player->plane_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}
