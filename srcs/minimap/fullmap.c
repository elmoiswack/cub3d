#include "../../includes/cub3d.h"
#include <stdio.h>

void	allocate_fullmap(t_minimap *mini)
{
	fullmap_make_floors(mini);
	fullmap_make_walls(mini);
	fullmap_make_background(mini);
}

void 	place_fullmap(t_minimap *mini)
{
	fullmap_place_background(mini);
	fullmap_place_floors(mini);
	fullmap_place_walls(mini);
}

void	create_fullmap(t_minimap *mini)
{
	allocate_fullmap(mini);
	place_fullmap(mini);
	disable_fullmap(mini);
}

void	disable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = false;
	mini->fullm_floor->enabled = false;
	mini->fullm_wall->enabled = false;
	if (mini->fullm_player)
	{
		mlx_delete_image(mini->mlx, mini->fullm_player);
		mini->fullm_player = NULL;
	}
	mini->fullmap_enabled = false;
}

void	enable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = true;
	mini->fullm_floor->enabled = true;
	mini->fullm_wall->enabled = true;
	if (!mini->fullm_player)
	{
		fullmap_make_player(mini);
		fullmap_place_player(mini);
	}
	mini->fullmap_enabled = true;
}
