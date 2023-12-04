#include "../includes/cub3d.h"
#include "stdio.h"

int	check_howmany_start(char **map)
{
	int	count;
	int	index;
	int	i;

	count = 0;
	index = 0;
	while (map[index])
	{
		i = 0;
		while (map[index][i])
		{
			if ((map[index][i] == 'N') || (map[index][i] == 'S') \
			|| (map[index][i] == 'E') || (map[index][i] == 'W'))
				count++;
			i++;
		}
		index++;
	}
	if (count != 1)
		return (-1);
	return (1);
}

void	get_start_pos(char **map, int *x, int *y)
{
	int	index;
	int	i;

	index = 0;
	while (map[index])
	{
		i = 0;
		while (map[index][i])
		{
			if ((map[index][i] == 'N') || (map[index][i] == 'S') \
			|| (map[index][i] == 'E') || (map[index][i] == 'W'))
			{
				*x = i;
				*y = index;
				return ;
			}
			i++;
		}
		index++;
	}
	return ;
}

int	valid_char(char c)
{
	if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (1);
	return (-1);
}

int	check_char_map(char	**map)
{
	int	index;
	int	i;

	index = 0;
	while (map[index])
	{
		i = 0;
		while (map[index][i])
		{
			if (valid_char(map[index][i]) == -1)
				return (-1);
			i++;
		}
		index++;
	}
	return (1);
}

int	floodfill(char	**map, int start_x, int start_y)
{

}

int	map_checker(char **map)
{
	int	start_x;
	int	start_y;
	char	**map_copy;
	
	if (check_howmany_start(map) == -1)
		return (-1);
	if (check_char_map(map) == -1)
		return (-1);
	start_x = 0;
	start_y = 0;
	get_start_pos(map, &start_x, &start_y);
	if (floodfill(map, start_x, start_y) == -1)
		return (-1);
	return (1);
}