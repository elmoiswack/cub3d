#include "../../includes/cub3d.h"
#include <stdio.h>

//draws the background onto the screen
void	mm_draw_background(t_minimap *minimap)
{
	int x;
	int y;

	x = 0;
	if (!minimap->screen_background)
	{
		minimap->screen_background = mlx_new_image(minimap->mlx, (MINIMAP_WIDTH), (MINIMAP_HEIGHT));
		mlx_image_to_window(minimap->mlx, minimap->screen_background, 0, 0);
	}
	else
	{
		mlx_delete_image(minimap->mlx, minimap->screen_background);
		minimap->screen_background = NULL;
		minimap->screen_background = mlx_new_image(minimap->mlx, MINIMAP_WIDTH, (MINIMAP_HEIGHT));
		mlx_image_to_window(minimap->mlx, minimap->screen_background, 0, 0);		
	}
	while (x < MINIMAP_WIDTH)
	{
		y = 0;
		while (y < (MINIMAP_HEIGHT))
		{
			mlx_put_pixel(minimap->screen_background, x, y, transfer_colour(0, 0, 0));
			y++;
		}
		x++;
	}
}

//draws the walls onto the screen
void	mm_place_walls(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_wall, (x * (MINIMAP_WIDTH / 3)), (y * (MINIMAP_HEIGHT / 3)));
}

//draws the floors onto the screen
void	mm_place_floors(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_floor, (x * (MINIMAP_WIDTH / 3)), (y * (MINIMAP_HEIGHT / 3)));
}

//draws the player onto the screen
void	mm_place_player(t_minimap *mini)
{
	mlx_image_to_window(mini->mlx, mini->screen_player, MINIMAP_WIDTH / 2 - 23, MINIMAP_HEIGHT / 2 + 23);
}