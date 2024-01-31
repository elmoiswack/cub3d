#include "../../includes/cub3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (-1);
}

//only the valid chars that are accepted inside the map
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
	return (index);
}

//gets the index on which the map starts in full_file
int	get_start_map(t_parser *parser_s)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (parser_s->full_file[index])
	{
		while (parser_s->full_file[index][j])
		{
			if (ft_isalpha(parser_s->full_file[index][0]) == 1)
				break ;
			if (parser_s->full_file[index][j] == '1')
				return (index);
			j++;
		}
		index++;
	}
	return (-1);	
}