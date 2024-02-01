#include "../../includes/cub3d.h"
#include <stdio.h>

void	allocate_fullmap(t_minimap *mini)
{
	fullmap_make_floors(mini);
	fullmap_make_walls(mini);
	fullmap_make_background(mini);
	fullmap_make_player(mini);
}

void	place_fullmap(t_minimap *mini)
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
	disable_fullmap(mini);
}
