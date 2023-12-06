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

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (-1);
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
	else if (is_whitespace(c) == 1)
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
		if (map[index][0] == '\n')
			return (-1);
		while (map[index][i] && map[index][i] != '\n')
		{
			if (valid_char(map[index][i]) == -1)
				return (-1);
			i++;
		}
		index++;
	}
	return (1);
}

int	get_max_2d(char **array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}

char	**copy_2d_array(char **array)
{
	char	**new;
	int		index;

	index = get_max_2d(array);
	new = ft_calloc(index + 1, sizeof(char *));
	if (!new)
		return (NULL);
	index = 0;
	while (array[index])
	{
		new[index] = ft_calloc(ft_strlen(array[index]) + 1, sizeof(char));
		if (!new[index])
			return (free_2d_array(new), NULL);
		ft_strlcpy(new[index], array[index], ft_strlen(array[index]) + 1);
		index++;
	}
	new[index] = NULL;
	return (new);
}

int	floodfill(char	**map, int start_x, int start_y)
{
	if ((start_x <= 0) || (start_y <= 0) || ((size_t) start_x >= ft_strlen(map[start_y]) - 2) 
		|| (start_y >= get_max_2d(map) - 1) || (map[start_y][start_x] == ' '))
		return (-1);
	map[start_y][start_x] = '@';
	if (map[start_y][start_x + 1] != '@' && map[start_y][start_x + 1] != '1')
	{
		if (floodfill(map, start_x + 1, start_y) == -1)
			return (-1);
	}
	if (map[start_y][start_x - 1] != '@' && map[start_y][start_x - 1] != '1')
	{
		if (floodfill(map, start_x - 1, start_y) == -1)
			return (-1);
	}
	if (map[start_y + 1][start_x] != '@' && map[start_y + 1][start_x] != '1')
	{
		if (floodfill(map, start_x, start_y + 1) == -1)
			return (-1);
	}
	if (map[start_y - 1][start_x] != '@' && map[start_y - 1][start_x] != '1')
	{
		if (floodfill(map, start_x, start_y - 1) == -1)
			return (-1);
	}
	return (1);
}

int	map_checker(char **map, t_parser *parser_s)
{
	int		start_x;
	int		start_y;
	char	**map_copy;
	
	if (check_howmany_start(map) == -1)
		return (-1);
	if (check_char_map(map) == -1)
		return (-1);
	start_x = 0;
	start_y = 0;
	get_start_pos(map, &start_x, &start_y);
	parser_s->start_posx = start_x;
	parser_s->start_posy = start_y;
	map_copy = copy_2d_array(map);
	if (!map_copy)
		return (-1);
	if (floodfill(map_copy, start_x, start_y) == -1)
		return (-1);
	return (1);
}