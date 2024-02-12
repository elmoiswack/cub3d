#include "../../includes/cub3d.h"

int	get_size_biggest_line(char **map)
{
	int	y;
	int	size;

	y = 0;
	size = (int)ft_strlen(map[y]);
	y++;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) > size)
			size = (int)ft_strlen(map[y]);
		y++;
	}
	return (size - 1);
}

char	**allocate_array_mm(t_minimap *mini)
{
	char	**arr;
	int		count;

	count = 0;
	arr = ft_calloc(6, sizeof(char *));
	if (!arr)
		error_game(mini->game, "allocation of array_mm failed!");
	arr[0] = ft_calloc(6, sizeof(char));
	arr[1] = ft_calloc(6, sizeof(char));
	arr[2] = ft_calloc(6, sizeof(char));
	arr[3] = ft_calloc(6, sizeof(char));
	arr[4] = ft_calloc(6, sizeof(char));
	arr[5] = NULL;
	while (arr[count])
		count++;
	if (count != 5)
		error_game(mini->game, "allocation of array_mm failed!");
	return (arr);
}

bool	out_of_map_x(char **map, int player_x, int player_y, int x)
{
	if (player_x + x > (int)ft_strlen(map[player_y]) - 1)
		return (true);
	if (player_x + x < 0)
		return (true);
	return (false);
}

bool	out_of_map_y(char **map, int player_y, int y)
{
	if (player_y + y > get_max_2d(map) - 1)
		return (true);
	if (player_y + y < 0)
		return (true);
	return (false);
}

void	create_minimap_border(t_minimap *mini)
{
	int	x;
	int	y;

	mini->minimap_border = mlx_new_image(mini->mlx, \
		mini->mm_scaler * 6, mini->mm_scaler * 6);
	if (!mini->minimap_border)
		error_game(mini->game, "Failed to allocate the minimap_border image!");
	y = 0;
	while (y < (mini->mm_scaler * 6))
	{
		x = 0;
		while (x < (mini->mm_scaler * 6))
		{
			mlx_put_pixel(mini->minimap_border, x, y, \
				transfer_colour(0, 0, 255));
			x++;
		}
		y++;
	}
}
