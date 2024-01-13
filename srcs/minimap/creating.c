#include "../../includes/cub3d.h"
#include <stdio.h>

//creates the images for the wall minimap
void	mm_make_walls(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	mini->screen_wall = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 3, MINIMAP_WIDTH / 3);
	while (x < MINIMAP_WIDTH / 3)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 3)
		{
			mlx_put_pixel(mini->screen_wall, x, y, transfer_colour(255, 255, 255));
			y++;
		}
		x++;
	}
}

//creates the images for the floor minimap
void	mm_make_floors(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	mini->screen_floor = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 3, MINIMAP_WIDTH / 3);
	while (x < MINIMAP_WIDTH / 3)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 3)
		{
			mlx_put_pixel(mini->screen_floor, x, y, transfer_colour(0, 255, 0));
			y++;
		}
		x++;
	}	
}

//creates the images for the player minimap
void	mm_make_player(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	mini->screen_player = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 20, MINIMAP_WIDTH / 20);
	while (x < MINIMAP_WIDTH / 20)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 20)
		{
			mlx_put_pixel(mini->screen_player, x, y, transfer_colour(255, 0, 0));
			y++;
		}
		x++;
	}		
}