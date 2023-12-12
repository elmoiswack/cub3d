#include "../../includes/cub3d.h"
#include "stdio.h"

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
	char	**map_copy;
	
	if (check_howmany_start(map) == -1)
		return (error_parser(parser_s, "Only 1 start position is needed, either an 'N', 'E', 'S' or 'W'!"), -1);
	if (check_char_map(map) == -1)
		return (error_parser(parser_s, "An invalid character is inside the map!"), -1);
	if (border_check(map) == -1)
		return (error_parser(parser_s, "Unclosed borders!"), -1);
	get_start_pos(map, &parser_s->start_posx, &parser_s->start_posy);
	map_copy = copy_2d_array(map);
	if (!map_copy)
		return (error_parser(parser_s, "Allocation map_copy failed!"), -1);
	if (floodfill(map_copy, parser_s->start_posx, parser_s->start_posy) == -1)
	{
		free_2d_array(map_copy);
		return (-1);
	}
	free_2d_array(map_copy);
	return (1);
}

int	alpha_in_path(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (ft_isalpha(line[index]) == 1)
			count++;
		index++;
	}
	if (count == 0)
		return (-1);
	return (1);
}

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

int	ammount_input_rgb(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] == ',')
			count++;
		index++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

int	overflow_check(char *line)
{
	int		index;
	char	*str;

	index = 1;
	if (ft_strlen(line) > 10)
		return (-1);
	if (ft_strlen(line) < 10)
		return (1);
	str = malloc(11 * sizeof(char));
	if (!str)
		return (-1);
	ft_strlcpy(str, "2147483647", ft_strlen("2147483647"));
	while (line[index] && line[index] != '\n')
	{
		if (line[index] > str[index])
		{
			free(str);
			return (-1);
		}
		index++;
	}
	free(str);
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

int	are_there_empty_inputs(t_parser *parser_s)
{
	if (!parser_s)
		return (-1);
	if (!parser_s->map)
		return (error_parser(parser_s, "Missing Map!"), -1);
	if (!parser_s->n_texture || alpha_in_path(parser_s->n_texture) == -1)
		return (error_parser(parser_s, "Missing North texture!"), -1);
	if (!parser_s->e_texture || alpha_in_path(parser_s->e_texture) == -1)
		return (error_parser(parser_s, "Missing East texture!"), -1);
	if (!parser_s->s_texture || alpha_in_path(parser_s->s_texture) == -1)
		return (error_parser(parser_s, "Missing South texture!"), -1);
	if (!parser_s->w_texture || alpha_in_path(parser_s->w_texture) == -1)
		return (error_parser(parser_s, "Missing West texture!"), -1);
	if (!parser_s->rgb_ceiling || rgb_checks(parser_s->rgb_ceiling) == -1)
		return (error_parser(parser_s, "Invalid Ceiling colours!"), -1);
	if (!parser_s->rgb_floor || rgb_checks(parser_s->rgb_floor) == -1)
		return (error_parser(parser_s, "Invalid Floor colours!"), -1);
	return (1);
}

t_parser *parser_checks(t_parser *parser_s)
{
	if (are_there_empty_inputs(parser_s) == -1)
		return (error_parser(parser_s, "Missing important information"), NULL);
	if (map_checker(parser_s->map, parser_s) == -1)
		return (error_parser(parser_s, "Invalid map"), NULL);
	return (parser_s);
}