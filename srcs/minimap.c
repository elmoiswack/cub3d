#include "../includes/cub3d.h"
#include <stdio.h>

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
			mlx_put_pixel(minimap->screen_background, x, y, compute_color(0, 0, 0));
			y++;
		}
		x++;
	}
}

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
			mlx_put_pixel(mini->screen_wall, x, y, compute_color(255, 255, 255));
			y++;
		}
		x++;
	}
}

void	mm_place_walls(t_minimap *mini)
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
				mlx_image_to_window(mini->mlx, mini->screen_wall, (x * MINIMAP_WIDTH / 30 + (MINIMAP_WIDTH / 11)), (y * MINIMAP_HEIGHT / 10 + (MINIMAP_WIDTH / 15)));
			}
			x++;
		}
		y++;
	}
}

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
			mlx_put_pixel(mini->screen_floor, x, y, compute_color(0, 255, 0));
			y++;
		}
		x++;
	}	
}

void	mm_place_floors(t_minimap *mini)
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
				mlx_image_to_window(mini->mlx, mini->screen_floor, (x * MINIMAP_WIDTH / 30 + (MINIMAP_WIDTH / 11)), (y * MINIMAP_HEIGHT / 10 + (MINIMAP_WIDTH / 15)));
			}
			x++;
		}
		y++;
	}
}

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
			mlx_put_pixel(mini->screen_player, x, y, compute_color(255, 0, 0));
			y++;
		}
		x++;
	}		
}

void	mm_place_player(t_minimap *mini)
{
	mlx_image_to_window(mini->mlx, mini->screen_player, (mini->player_x * MINIMAP_WIDTH / 30 + (MINIMAP_WIDTH / 11)), (mini->player_y * MINIMAP_HEIGHT / 10 + (MINIMAP_WIDTH / 15)));
}

void	minimap(t_minimap *minimap)
{
	mm_draw_background(minimap);
	mm_make_walls(minimap);
	mm_place_walls(minimap);
	mm_make_floors(minimap);
	mm_place_floors(minimap);
	mm_make_player(minimap);
	mm_place_player(minimap);
	return ;
}