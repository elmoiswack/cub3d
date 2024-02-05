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

bool	check_line_for_map(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == '\n')
			return (true);
		if (ft_isdigit(line[index]) == 0)
			return (false);
		index++;
	}
	return (true);
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
			if (ft_isdigit(parser_s->full_file[index][j]) == 1)
			{
				if (check_line_for_map(parser_s->full_file[index]) == true)
					return (index);
				else
					break ;
			}
			j++;
		}
		index++;
	}
	return (-1);
}
