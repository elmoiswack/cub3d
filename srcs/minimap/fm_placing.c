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
				mlx_image_to_window(mini->mlx, mini->fullm_wall, (x * FULLMAP_WIDTH / 27.8 + (FULLMAP_WIDTH / 15.5) + 40), (y * FULLMAP_HEIGHT / 9 + (FULLMAP_HEIGHT / 10) + 25));
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
				mlx_image_to_window(mini->mlx, mini->fullm_floor, (x * FULLMAP_WIDTH / 40 + (FULLMAP_WIDTH / 25) + 40), (y * FULLMAP_HEIGHT / 40 + (FULLMAP_WIDTH / 25) + 25));
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
	mlx_image_to_window(mini->mlx, mini->fullm_player, ((mini->player_x - 0.5) * FULLMAP_WIDTH / 27.8 + (FULLMAP_WIDTH / 15.5) + 40), (mini->player_y * FULLMAP_HEIGHT / 19 + (FULLMAP_WIDTH / 10) + 25));
}