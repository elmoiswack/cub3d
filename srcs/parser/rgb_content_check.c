#include "../../includes/cub3d.h"
#include "stdio.h"

int	check_chars_rgb(char *line)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
	{
		if (ft_isdigit(line[index]) != 1 && line[index] != ',')
			return (-1);
		index++;
	}
	return (1);
}

int	range_compare(char *line)
{
	int	temp;
	int	min;
	int	max;

	min = 0;
	max = 255;
	if (overflow_check(line) == -1)
		return (-1);
	temp = ft_atoi(line);
	if (temp < min || temp > max)
		return (-1);
	return (1);
}

int	get_single_rgb_value(char *line, int index, int begin)
{
	char	*temp;

	temp = ft_substr(line, begin, index - begin);
	if (!temp)
		return (-1);
	if (range_compare(temp) == -1)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (1);
}

int	check_range_rgb(char *line)
{
	int		index;
	int		begin;

	index = 0;
	while (line[index])
	{
		if (line[index] == ',' || line[index + 1] == '\0')
		{
			if (line[index + 1] == '\0')
				index++;
			begin = index;
			begin--;
			while (begin > 0 && line[begin] != ',')
				begin--;
			if (line[begin] == ',')
				begin++;
			if (get_single_rgb_value(line, index, begin) == -1)
				return (-1);
		}
		if (line[index] != '\0')
			index++;
	}
	return (1);
}

int	rgb_checks(char *line)
{
	if (check_chars_rgb(line) == -1)
		return (-1);
	if (ammount_input_rgb(line) == -1)
		return (-1);
	if (check_range_rgb(line) == -1)
		return (-1);
	return (1);
}
