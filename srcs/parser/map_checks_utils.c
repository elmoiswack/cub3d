#include "../../includes/cub3d.h"

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

int	skip_whitespaces(char *line, int index)
{
	while (line[index] && is_whitespace(line[index]) == 1)
		index++;
	return (1);
}