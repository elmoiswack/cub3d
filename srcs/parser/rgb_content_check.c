#include "../../includes/cub3d.h"
#include "stdio.h"

//checks if there are letters inside of the texture adresses
//if not, the texture is 100% invalid because it's in a folder called textures
int	alpha_in_texture(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (ft_isalpha(line[index]) == 1 || line[index] == '/')
			count++;
		index++;
	}
	if (count == 0)
		return (-1);
	return (1);
}

//checks if there are only numbers and a ','
//the ',' is used to seperate the r, g and b
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

//checks that the current r, g or b is between 0 and 255
//if not, it is an invalid r, g or b value and -1 is returned
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

//the ft is a loop checks if the entire rgb is valid
int	check_range_rgb(char *line)
{
	int		index;
	int		begin;
	char	*temp;

	index = 0;
	while(line[index])
	{
		if (line[index] == ',' || line[index] == '\n')
		{
			begin = index;
			begin--;
			while (begin > 0 && line[begin] != ',')
				begin--;
			if (line[begin] == ',')
				begin++;
			temp = ft_substr(line, begin, index - begin);
			if (!temp)
				return (-1);
			if (range_compare(temp) == -1)
			{
				free(temp);
				return (-1);
			}
			free(temp);
		}
		if (line[index] != '\0')
			index++;
	}
	return (1);
}