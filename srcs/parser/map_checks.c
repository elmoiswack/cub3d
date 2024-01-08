#include "../../includes/cub3d.h"
#include "stdio.h"

//ft checks how many start_positions there are
//if there isn't one, -1 is returned and when there are more then 1 start_positions
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

//gets the start_position of the player and the direction they are facing
void	get_start_pos(char **map, int *x, int *y, char *start_derection)
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
				*start_derection = map[index][i];
				return ;
			}
			i++;
		}
		index++;
	}
	return ;
}

//checks all the chars in the map to see if there is an invalid char
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

//checks the border of the map
//say there are whitespaces inbetween walls, it skips them to check if the next occurence of a char is a '1'
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
