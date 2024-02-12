#include "../../includes/cub3d.h"
#include "stdio.h"

void	trim_nl_arr(char **map)
{
	int	index;

	index = get_max_2d(map);
	index--;
	while (map[index][0] == '\n')
	{
		free(map[index]);
		map[index] = NULL;
		index--;
	}
}
