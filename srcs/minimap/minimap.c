#include "../../includes/cub3d.h"
#include <stdio.h>

//the main minimap start
void	minimap(t_minimap *minimap)
{
	if (minimap->redraw == true)
	{
		mm_draw_background(minimap);
		mm_make_walls(minimap);
		mm_place_walls(minimap);
		mm_make_floors(minimap);
		mm_place_floors(minimap);
		mm_make_player(minimap);
		mm_place_player(minimap);
	}
	return ;
}