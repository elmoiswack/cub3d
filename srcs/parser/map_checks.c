#include "../../includes/cub3d.h"
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

int	border_check(char **map)
{
	int	index;
	int	i;

	index = 0;
	while (map[index])
	{
		i = 0;
		if (map[index][0] == ' ')
			i = skip_whitespaces(map[index], i);
		if (map[index][i] != '1')
			return (-1);
		while (map[index][i] && (map[index][i] != '\n' && map[index][i] != ' '))
			i++;
		if (map[index][i] == '\0' && map[index + 1] != NULL)
			return (-1);
		while (map[index][i] == ' ')
		{
			if (map[index][i - 1] != '1')
				return (-1);
			i = skip_whitespaces(map[index], i);
			if (map[index][i] != '1')
				return (-1);
		}
		if (map[index][i - 1] != '1')
			return (-1);
		index++;
	}
	return (1);
}
