#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_make_walls(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	mini->fullm_wall = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 20, FULLMAP_HEIGHT / 9);
	while (x < (FULLMAP_WIDTH / 20))
	{
		y = 0;
		while (y < (FULLMAP_HEIGHT / 9))
		{
			mlx_put_pixel(mini->fullm_wall, x, y, transfer_colour(255, 255, 255));
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
	mini->fullm_floor = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 3, FULLMAP_HEIGHT / 1.5);
	while (x < FULLMAP_WIDTH / 3)
	{
		y = 0;
		while (y < FULLMAP_HEIGHT / 1.5)
		{
			mlx_put_pixel(mini->fullm_floor, x, y, transfer_colour(0, 255, 0));
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
	mini->fullm_player = mlx_new_image(mini->mlx, FULLMAP_WIDTH / 30, FULLMAP_HEIGHT / 20);
	while (x < FULLMAP_WIDTH / 30)
	{
		y = 0;
		while (y < FULLMAP_HEIGHT / 20)
		{
			mlx_put_pixel(mini->fullm_player, x, y, transfer_colour(255, 0, 0));
			y++;
		}
		x++;
	}		
}

void	fullmap_make_background(t_minimap *mini)
{
	int	x;
	int y;

	mini->fullm_background = mlx_new_image(mini->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			mlx_put_pixel(mini->fullm_background, x, y, transfer_colour(0, 0, 0));
			y++;
		}
		x++;
	}
}