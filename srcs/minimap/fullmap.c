#include "../../includes/cub3d.h"
#include <stdio.h>

void	fullmap_place_background(t_minimap *mini)
{
	int	x;
	int y;

	if (mini->screen_background)
	{
		mlx_delete_image(mini->mlx, mini->screen_background);
		mini->screen_background = NULL;
		mini->screen_background = mlx_new_image(mini->mlx, FULLMAP_WIDTH, FULLMAP_HEIGHT);
		mlx_image_to_window(mini->mlx, mini->screen_background, 20, 15);
	}
	x = 40;
	while (x < FULLMAP_WIDTH)
	{
		y = 25;
		while (y < FULLMAP_HEIGHT)
		{
			mlx_put_pixel(mini->screen_background, x, y, transfer_colour(0, 0, 0));
			y++;
		}
		x++;
	}
}

void 	minimap_fullmap_window(t_minimap *mini)
{
	//fullmap_make_player(mini);
	fullmap_make_floors(mini); //done
	fullmap_make_walls(mini);
	fullmap_place_background(mini); //done
	fullmap_place_floors(mini); //done
	fullmap_place_walls(mini);
	//fullmap_place_player(mini);
	mini->open = true;
}

void	minimap_close_fullmap(t_minimap *minimap)
{
	mlx_delete_image(minimap->mlx, minimap->screen_background);
	minimap->screen_background = NULL;
	mlx_delete_image(minimap->mlx, minimap->screen_floor);
	minimap->screen_floor = NULL;
	mlx_delete_image(minimap->mlx, minimap->screen_wall);
	minimap->screen_wall = NULL;
	mlx_delete_image(minimap->mlx, minimap->screen_player);
	minimap->screen_player = NULL;
	create_minimap(minimap);
	minimap->open = false;
}