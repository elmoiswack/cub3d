#include "../../includes/cub3d.h"
#include <stdio.h>

char	**fill_array_mm(char **array, char **map, int player_x, int player_y)
{
	int	y;
	int	x;

	y = -2;
	while (y < 3)
	{
		x = -2;
		while (x < 3)
		{
			if (out_of_map_x(map, player_x, player_y, x) == true \
				|| out_of_map_y(map, player_y, y) == true)
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

void	draw_onto_image(t_minimap *mini, int x, int y, uint32_t color)
{
	int	x_max;
	int	y_max;
	int	temp;

	x_max = (x + 1) * mini->mm_scaler;
	y_max = (y + 1) * mini->mm_scaler;
	x = x * mini->mm_scaler;
	temp = y * mini->mm_scaler;
	if (x_max > MINIMAP_WIDTH)
		x_max = MINIMAP_WIDTH;
	if (y_max > MINIMAP_HEIGHT)
		y_max = MINIMAP_HEIGHT;
	while (x < x_max)
	{
		y = temp;
		while (y < y_max)
		{
			mlx_put_pixel(mini->minimap_image, x, y, color);
			y++;
		}
		x++;
	}
}

void	mm_place_content(char **array, t_minimap *mini)
{
	int	y;
	int	x;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == '-')
				draw_onto_image(mini, x, y, transfer_colour(0, 0, 0));
			else if (array[y][x] == '0')
				draw_onto_image(mini, x, y, transfer_colour(0, 255, 0));
			else if (array[y][x] == '1')
				draw_onto_image(mini, x, y, transfer_colour(255, 255, 255));
			else if (array[y][x] == 'P')
				draw_onto_image(mini, x, y, transfer_colour(255, 0, 0));
			x++;
		}
		y++;
	}
}

void	place_minimap_border(t_minimap *mini)
{
	if (mlx_image_to_window(mini->mlx, mini->minimap_border, 0, 0) == -1)
		error_game(mini->game, \
			"Failed to place the border surrounding the minimap mm!");
}

void	create_minimap(t_minimap *mini)
{
	char	**arr;

	if (!mini->minimap_image)
	{
		mini->minimap_image = \
			mlx_new_image(mini->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
		if (!mini->minimap_image)
			error_game(mini->game, "Failed to allocate the minimap image!");
	}
	if (!mini->minimap_border)
	{
		create_minimap_border(mini);
		place_minimap_border(mini);
	}
	arr = allocate_array_mm(mini);
	arr = fill_array_mm(arr, mini->file_map, mini->player_x, mini->player_y);
	mm_place_content(arr, mini);
	if (mlx_image_to_window(mini->mlx, mini->minimap_image, \
		mini->mm_scaler / 2, mini->mm_scaler / 2) == -1)
		error_game(mini->game, "Failed to place the minimap image!");
	free_2d_array(arr);
	return ;
}
