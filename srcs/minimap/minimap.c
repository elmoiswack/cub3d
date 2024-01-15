#include "../../includes/cub3d.h"
#include <stdio.h>

void	mm_place_content(char	**map, int x, int y, t_minimap *mini)
{
	mm_place_floors(mini, 1, 1);
	if (map[y][x + 1])
	{
		if (map[y][x + 1] == '0')
			mm_place_floors(mini, x + 1, y);
		else if (map[y][x + 1] == '1')
			mm_place_walls(mini, x + 1, y);
	}
	if (map[y][x - 1])
	{
		if (map[y][x - 1] == '0')
			mm_place_floors(mini, x - 1, y);
		else if (map[y][x - 1] == '1')
			mm_place_walls(mini, x - 1, y);
	}
	if (map[y + 1][x])
	{
		if (map[y + 1][x] == '0')
			mm_place_floors(mini, x, y + 1);
		else if (map[y + 1][x] == '1')
			mm_place_walls(mini, x, y + 1);
	}
	if (map[y - 1][x])
	{
		if (map[y - 1][x] == '0')
			mm_place_floors(mini, x, y - 1);
		else if (map[y - 1][x] == '1')
			mm_place_walls(mini, x, y - 1);
	}
	if (map[y + 1][x + 1])
	{
		if (map[y + 1][x + 1] == '0')
			mm_place_floors(mini, x + 1, y + 1);
		else if (map[y + 1][x + 1] == '1')
			mm_place_walls(mini, x + 1, y + 1);
	}
	if (map[y - 1][x + 1])
	{
		if (map[y - 1][x + 1] == '0')
			mm_place_floors(mini, x + 1, y - 1);
		else if (map[y - 1][x + 1] == '1')
			mm_place_walls(mini, x + 1, y - 1);
	}
	if (map[y + 1][x - 1])
	{
		if (map[y + 1][x - 1] == '0')
			mm_place_floors(mini, x - 1, y + 1);
		else if (map[y + 1][x - 1] == '1')
			mm_place_walls(mini, x - 1, y + 1);
	}
	if (map[y - 1][x - 1])
	{
		if (map[y - 1][x - 1] == '0')
			mm_place_floors(mini, x - 1, y - 1);
		else if (map[y - 1][x - 1] == '1')
			mm_place_walls(mini, x - 1, y - 1);
	}
}

char	**fill_array(char **array, char **map, int player_x, int player_y)
{
	array[1][1] = 'P';
	if (map[player_y][player_x + 1])
	{
		if (map[player_y][player_x + 1] == '0')
			array[1][2] = '0';
		if (map[player_y][player_x + 1] == '1')
			array[1][2] = '1';
	}
	if (map[player_y][player_x - 1])
	{
		if (map[player_y][player_x - 1] == '0')
			array[1][0] = '0';
		if (map[player_y][player_x - 1] == '1')
			array[1][0] = '1';
	}
	if (map[player_y + 1][player_x])
	{
		if (map[player_y + 1][player_x] == '0')
			array[2][1] = '0';
		if (map[player_y + 1][player_x] == '1')
			array[2][1] = '1';
	}
	if (map[player_y - 1][player_x])
	{
		if (map[player_y - 1][player_x] == '0')
			array[0][1] = '0';
		if (map[player_y - 1][player_x] == '1')
			array[0][1] = '1';
	}
	if (map[player_y + 1][player_x + 1])
	{
		if (map[player_y + 1][player_x + 1] == '0')
			array[2][2] = '0';
		if (map[player_y + 1][player_x + 1] == '1')
			array[2][2] = '1';
	}
	if (map[player_y - 1][player_x + 1])
	{
		if (map[player_y - 1][player_x + 1] == '0')
			array[0][2] = '0';
		if (map[player_y - 1][player_x + 1] == '1')
			array[0][2] = '1';
	}
	if (map[player_y + 1][player_x - 1])
	{
		if (map[player_y + 1][player_x - 1] == '0')
			array[2][0] = '0';
		if (map[player_y + 1][player_x - 1] == '1')
			array[2][0] = '1';
	}
	if (map[player_y - 1][player_x - 1])
	{
		if (map[player_y - 1][player_x - 1] == '0')
			array[0][0] = '0';
		if (map[player_y - 1][player_x - 1] == '1')
			array[0][0] = '1';
	}
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
	if (!mini->screen_background)
		mm_draw_background(mini);
}

//the main minimap start
void	create_minimap(t_minimap *minimap)
{
	char	**arr;

	delete_minimap(minimap);
	arr = ft_calloc(4, sizeof(char *));
	arr[0] = ft_calloc(4, sizeof(char));
	arr[1] = ft_calloc(4, sizeof(char));
	arr[2] = ft_calloc(4, sizeof(char));
	arr[3] = NULL;
	arr = fill_array(arr, minimap->file_map, minimap->player_x, minimap->player_y);
	allocate_images(minimap);
	mm_place_content(arr, 1, 1, minimap);
	mm_place_player(minimap);
	free_2d_array(arr);
	return ;
}

void	enable_minimap(t_minimap *mini)
{
	mini->screen_background->enabled = true;
	mini->screen_floor->enabled = true;
	mini->screen_player->enabled = true;
	mini->screen_wall->enabled = true;
	mini->minimap_enabled = true;
}

void	disable_minimap(t_minimap *mini)
{
	mini->screen_background->enabled = false;
	mini->screen_floor->enabled = false;
	mini->screen_player->enabled = false;
	mini->screen_wall->enabled = false;
	mini->minimap_enabled = false;
}

void	delete_minimap(t_minimap *mini)
{
	if (mini->screen_background)
	{
		mlx_delete_image(mini->mlx, mini->screen_background);
		mini->screen_background = NULL;
	}
	if (mini->screen_floor)
	{
		mlx_delete_image(mini->mlx, mini->screen_floor);
		mini->screen_floor = NULL;
	}
	if (mini->screen_player)
	{
		mlx_delete_image(mini->mlx, mini->screen_player);
		mini->screen_player = NULL;
	}
	if (mini->screen_wall)
	{
		mlx_delete_image(mini->mlx, mini->screen_wall);
		mini->screen_wall = NULL;
	}
}