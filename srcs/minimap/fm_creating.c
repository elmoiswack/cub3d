#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_make_walls(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	if (!mini->screen_wall)
	{
		mini->screen_wall = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 6, FULLMAP_HEIGHT / 3);
	}
	while (x < FULLMAP_WIDTH / 6)
	{
		y = 0;
		while (y < FULLMAP_HEIGHT / 3)
		{
			mlx_put_pixel(mini->screen_wall, x, y, transfer_colour(255, 255, 255));
			y++;
		}
		x++;
	}
}

//creates the images for the floor minimap
void	fullmap_make_floors(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	if (!mini->screen_floor)
	{
		mini->screen_floor = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 3, FULLMAP_HEIGHT / 1.5);
	}

	while (x < FULLMAP_WIDTH / 3)
	{
		y = 0;
		while (y < FULLMAP_HEIGHT / 1.5)
		{
			mlx_put_pixel(mini->screen_floor, x, y, transfer_colour(0, 255, 0));
			y++;
		}
		x++;
	}	
}

//creates the images for the player minimap
void	fullmap_make_player(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	if (!mini->screen_player)
	{
		mini->screen_player = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 20, FULLMAP_HEIGHT / 15);
	}
	while (x < FULLMAP_WIDTH / 20)
	{
		y = 0;
		while (y < FULLMAP_HEIGHT / 15)
		{
			mlx_put_pixel(mini->screen_player, x, y, transfer_colour(255, 0, 0));
			y++;
		}
		x++;
	}		
}