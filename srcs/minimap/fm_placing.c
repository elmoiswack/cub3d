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
				mlx_image_to_window(mini->mlx, mini->screen_wall, (x * FULLMAP_WIDTH / 40 + (FULLMAP_WIDTH / 25) + 45), (y * FULLMAP_HEIGHT / 40 + (FULLMAP_WIDTH / 25) + 25));
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
				mlx_image_to_window(mini->mlx, mini->screen_floor, (x * FULLMAP_WIDTH / 40 + (FULLMAP_WIDTH / 25) + 45), (y * FULLMAP_HEIGHT / 40 + (FULLMAP_WIDTH / 25) + 25));
			}
			x++;
		}
		y++;
	}
}


//draws the player onto the screen
void	fullmap_place_player(t_minimap *mini)
{
	mlx_image_to_window(mini->mlx, mini->screen_player, ((mini->player_x - 0.5) * FULLMAP_WIDTH / 160 + (FULLMAP_WIDTH / 122)), ((mini->player_y - 0.5) * FULLMAP_HEIGHT / 40 + (FULLMAP_WIDTH / 35)));
}