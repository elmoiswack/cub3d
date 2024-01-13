#include "../../includes/cub3d.h"
#include <stdio.h>

void	allocate_fullmap(t_minimap *mini)
{
	fullmap_make_floors(mini);
	fullmap_make_player(mini);
	fullmap_make_walls(mini);
	fullmap_make_background(mini);
}

void 	place_fullmap(t_minimap *mini)
{
	fullmap_place_background(mini);
	fullmap_place_floors(mini);
	fullmap_place_walls(mini);
	fullmap_place_player(mini);
}

void	create_fullmap(t_minimap *mini)
{
	allocate_fullmap(mini);
	place_fullmap(mini);
}

void	disable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = false;
	mini->fullm_floor->enabled = false;
	mini->fullm_wall->enabled = false;
	mini->fullm_player->enabled = false;
	mlx_delete_image(mini->mlx, mini->fullm_player);
}

void	enable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = true;
	mini->fullm_floor->enabled = true;
	mini->fullm_wall->enabled = true;
	fullmap_make_player(mini);
	fullmap_place_player(mini);
}

void	delete_fullmap(t_minimap *minimap)
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
}