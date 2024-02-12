#include "../../includes/cub3d.h"
#include "stdio.h"

void	trim_nl_arr(char **map)
{
	int	index;
	int	i;

	index = get_max_2d(map);
	index--;
	while (map[index])
	{
		i = 0;
		while (map[index][i])
		{
			if (ft_isalnum(map[index][i]) == 1)
				return ;
			i++;
		}
		free(map[index]);
		map[index] = NULL;
		index--;
	}
}

int	new_line_check_map(char **map, int index, int i)
{
	while (map[index])
	{
		i = 0;
		while (map[index][i])
		{
			if (ft_isalnum(map[index][i]) == 1)
				return (-1);
			i++;
		}
		index++;
	}
	if (map[index] == NULL)
		return (1);
	return (-1);
}
