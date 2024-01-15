#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_make_walls(t_minimap *mini)
{
	int x;
	int y;

	x = 0;
	mini->fullm_wall = mlx_new_image(mini->mlx, mini->fm_scaler, mini->fm_scaler);
	while (x < (mini->fm_scaler))
	{
		y = 0;
		while (y < (mini->fm_scaler))
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
	mini->fullm_floor = mlx_new_image(mini->mlx, mini->fm_scaler, mini->fm_scaler);
	while (x < mini->fm_scaler)
	{
		y = 0;
		while (y < mini->fm_scaler)
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
	mini->fullm_player = mlx_new_image(mini->mlx, mini->fm_scaler / 2, mini->fm_scaler / 2);
	while (x < mini->fm_scaler / 2)
	{
		y = 0;
		while (y < mini->fm_scaler / 2)
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