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

bool		out_of_border_x(char **map, int player_x, int player_y, int x)
{
	if (player_x + x > (int)ft_strlen(map[player_y]) - 2)
		return (true);
	if (player_x + x < 0)
		return (true);
	return (false); 
}

bool		out_of_border_y(char **map, int player_y, int y)
{
	if (player_y + y > get_max_2d(map) - 1)
		return (true);
	if (player_y + y < 0)
		return (true);
	return (false);
}

char **fill_array(char **array, char **map, int player_x, int player_y)
{
	int	y;
	int	x;

	y = -2;
	while (y < 3)
	{
		x = -2;
		while (x < 3)
		{
			if (out_of_border_x(map, player_x, player_y, x) == true || out_of_border_y(map, player_y, y) == true)
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

void	allocate_images(t_minimap *mini)
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

//the main minimap start
void	create_minimap(t_minimap *minimap)
{
	char	**arr;

	delete_minimap(minimap);
	arr = ft_calloc(6, sizeof(char *));
	arr[0] = ft_calloc(6, sizeof(char));
	arr[1] = ft_calloc(6, sizeof(char));
	arr[2] = ft_calloc(6, sizeof(char));
	arr[3] = ft_calloc(6, sizeof(char));
	arr[4] = ft_calloc(6, sizeof(char));
	arr[5] = NULL;
	arr = fill_array(arr, minimap->file_map, minimap->player_x, minimap->player_y);
	allocate_images(minimap);
	mm_place_content(arr, minimap);
	free_2d_array(arr);
	return ;
}

void	enable_minimap(t_minimap *mini)
{
	mini->screen_border->enabled = true;
	mini->screen_floor->enabled = true;
	mini->screen_player->enabled = true;
	mini->screen_wall->enabled = true;
	mini->minimap_enabled = true;
}

void	disable_minimap(t_minimap *mini)
{
	mini->screen_border->enabled = false;
	mini->screen_floor->enabled = false;
	mini->screen_player->enabled = false;
	mini->screen_wall->enabled = false;
	mini->minimap_enabled = false;
}
