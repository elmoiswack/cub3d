#include "../../includes/cub3d.h"
#include <stdio.h>

//creates the images for the wall minimap
void	mm_make_walls(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	if (!mini->screen_wall)
	{
		mini->screen_wall = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 25, MINIMAP_WIDTH / 16);
	}
	else
	{
		mlx_delete_image(mini->mlx, mini->screen_wall);
		mini->screen_wall = NULL;
		mini->screen_wall = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 25, MINIMAP_WIDTH / 16);	
	}
	while (x < MINIMAP_WIDTH / 25)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 16)
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
	if (!mini->screen_floor)
	{
		mini->screen_floor = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 25, MINIMAP_WIDTH / 16);
	}
	else
	{
		mlx_delete_image(mini->mlx, mini->screen_floor);
		mini->screen_floor = NULL;
		mini->screen_floor = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 25, MINIMAP_WIDTH / 16);	
	}
	while (x < MINIMAP_WIDTH / 25)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 16)
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
	if (!mini->screen_player)
	{
		mini->screen_player = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 50, MINIMAP_WIDTH / 40);
	}
	else
	{
		mlx_delete_image(mini->mlx, mini->screen_player);
		mini->screen_player = NULL;
		mini->screen_player = mlx_new_image(mini->mlx, MINIMAP_WIDTH / 50, MINIMAP_WIDTH / 40);	
	}
	while (x < MINIMAP_WIDTH / 50)
	{
		y = 0;
		while (y < MINIMAP_WIDTH / 40)
		{
			mlx_put_pixel(mini->screen_player, x, y, transfer_colour(255, 0, 0));
			y++;
		}
		x++;
	}		
}