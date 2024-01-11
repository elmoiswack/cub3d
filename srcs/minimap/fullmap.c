#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_place_background(t_minimap *mini)
{
	int	x;
	int y;
	
	mini->fullm_background = mlx_new_image(mini->mlx, FULLMAP_WIDTH, FULLMAP_HEIGHT);
	mlx_image_to_window(mini->mlx, mini->fullm_background, 20, 15);
	x = 40;
	while (x < FULLMAP_WIDTH)
	{
		y = 25;
		while (y < FULLMAP_HEIGHT)
		{
			mlx_put_pixel(mini->fullm_background, x, y, transfer_colour(0, 0, 0));
			y++;
		}
		x++;
	}
}

void 	minimap_fullmap_window(t_minimap *mini)
{
	fullmap_make_floors(mini);
	fullmap_make_walls(mini);
	fullmap_make_player(mini);
	fullmap_place_background(mini);
	fullmap_place_floors(mini);
	fullmap_place_walls(mini);
	fullmap_place_player(mini);
	mini->fm_open = true;
}

void	minimap_close_fullmap(t_minimap *minimap)
{
	if (minimap->fullm_background)
	{
	    mlx_delete_image(minimap->mlx, minimap->fullm_background);
	    minimap->fullm_background = NULL;
	}
	if (minimap->fullm_floor)
	{
	    mlx_delete_image(minimap->mlx, minimap->fullm_floor);
    	minimap->fullm_floor = NULL;
	}
	if (minimap->fullm_player)
	{
	   mlx_delete_image(minimap->mlx, minimap->fullm_player);
	   minimap->fullm_player = NULL;
	}
	if (minimap->fullm_wall)
	{
	   mlx_delete_image(minimap->mlx, minimap->fullm_wall);
    	minimap->fullm_wall = NULL;
	}
	minimap->fm_open = false;
}