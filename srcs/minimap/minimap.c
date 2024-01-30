#include "../../includes/cub3d.h"
#include <stdio.h>

void	mm_place_content(char **array, t_minimap *mini)
{
	int y;
	int x;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == '-')	
				mm_place_border(mini, x, y);
			else if (array[y][x] == '0')
				mm_place_floors(mini, x, y);
			else if (array[y][x] == '1')
				mm_place_walls(mini, x, y);
			else if (array[y][x] == 'P')
			{
				mm_place_floors(mini, x, y);
				mm_place_player(mini, x, y);
			}
			x++;
		}
		y++;
	}
}

char **fill_array_mm(char **array, char **map, int player_x, int player_y)
{
	int	y;
	int	x;

	y = -2;
	while (y < 3)
	{
		x = -2;
		while (x < 3)
		{
			if (out_of_map_x(map, player_x, player_y, x) == true || out_of_map_y(map, player_y, y) == true)
				array[y + 2][x + 2] = '-';
			else if (map[player_y + y][player_x + x] == '0')
				array[y + 2][x + 2] = '0';
			else if (map[player_y + y][player_x + x] == '1')
				array[y + 2][x + 2] = '1';
			x++;
		}
		y++;
	}
	array[2][2] = 'P';
	return (array);
}

void	allocate_images_mm(t_minimap *mini)
{
	if (!mini->screen_player)
		mm_make_player(mini);
	if (!mini->screen_wall)
		mm_make_walls(mini);
	if (!mini->screen_floor)
		mm_make_floors(mini);
	if (!mini->screen_border)
		mm_make_border(mini);
}

void	create_minimap(t_minimap *minimap)
{
	char	**arr;

	arr = allocate_array_mm(minimap);
	arr = fill_array_mm(arr, minimap->file_map, minimap->player_x, minimap->player_y);
	mm_place_content(arr, minimap);
	free_2d_array(arr);
	return ;
}