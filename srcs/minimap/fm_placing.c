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
				mlx_image_to_window(mini->mlx, mini->fullm_wall, (x * mini->fm_scaler), (y * mini->fm_scaler + mini->fm_offset));
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
				mlx_image_to_window(mini->mlx, mini->fullm_floor, (x * mini->fm_scaler), (y * mini->fm_scaler + mini->fm_offset));
			}
			x++;
		}
		y++;
	}
}

void	fullmap_place_background(t_minimap *mini)
{
	mlx_image_to_window(mini->mlx, mini->fullm_background, 0, 0);
}


//draws the player onto the screen
void	fullmap_place_player(t_minimap *mini)
{
	mlx_image_to_window(mini->mlx, mini->fullm_player, (mini->player_x * mini->fm_scaler - 0.5), (mini->player_y * mini->fm_scaler - 0.5 + mini->fm_offset));
}