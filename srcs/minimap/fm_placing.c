/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_placing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:13:47 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:13:48 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_place_walls(t_minimap *mini)
{
	int	x;
	int	y;

	y = 0;
	while (mini->file_map[y])
	{
		x = 0;
		while (mini->file_map[y][x])
		{
			if (mini->file_map[y][x] == '1')
			{
				if (mlx_image_to_window(mini->mlx, mini->fullm_wall, \
					(x * mini->fm_scaler), \
					(y * mini->fm_scaler + mini->fm_offset_y)) == -1)
					error_game(mini->game, "Failed to place the wall fm!");
			}
			x++;
		}
		y++;
	}
}

//draws the floors onto the screen
void	fullmap_place_floors(t_minimap *mini)
{
	int	x;
	int	y;

	y = 0;
	while (mini->file_map[y])
	{
		x = 0;
		while (mini->file_map[y][x])
		{
			if (mini->file_map[y][x] == '0')
			{
				if (mlx_image_to_window(mini->mlx, mini->fullm_floor, \
					(x * mini->fm_scaler), \
					(y * mini->fm_scaler + mini->fm_offset_y)) == -1)
					error_game(mini->game, "Failed to place the floor fm!");
			}
			x++;
		}
		y++;
	}
}

void	fullmap_place_background(t_minimap *mini)
{
	if (mlx_image_to_window(mini->mlx, mini->fullm_background, 0, 0) == -1)
		error_game(mini->game, "Failed to place the background fm!");
}

//draws the player onto the screen
void	fullmap_place_player(t_minimap *mini)
{
	if (mlx_image_to_window(mini->mlx, mini->fullm_player, \
		(((int)mini->player_x) * mini->fm_scaler), \
		(((int)mini->player_y) * mini->fm_scaler) + mini->fm_offset_y) == -1)
		error_game(mini->game, "Failed to place the player fm!");
}
