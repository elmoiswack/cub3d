#include "../../includes/cub3d.h"
#include "stdio.h"

int	floodfill_check(char **map, int start_x, int start_y)
{
	if ((start_x <= 0) || (start_y <= 0) || \
		(start_x >= (int)ft_strlen(map[start_y]) - 2) || \
		(start_y >= get_max_2d(map) - 1) || \
		(map[start_y][start_x] == ' '))
		return (-1);
	return (1);
}

int	floodfill(char	**map, int start_x, int start_y)
{
	if (floodfill_check(map, start_x, start_y) == -1)
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
		error_parser(parser_s, "Only 1 start position is needed, \
			either an 'N', 'E', 'S' or 'W'!");
	if (check_char_map(map) == -1)
		error_parser(parser_s, "An invalid character is inside the map!");
	if (border_check(map, 0) == -1)
		error_parser(parser_s, "Unclosed borders!");
	get_start_pos(map, &parser_s->start_pos_x, &parser_s->start_pos_y, \
		&parser_s->start_direction);
	map_copy = copy_2d_array(map);
	if (!map_copy)
		error_parser(parser_s, "Allocation map_copy failed!");
	if (floodfill(map_copy, parser_s->start_pos_x, parser_s->start_pos_y) == -1)
	{
		free_2d_array(map_copy);
		return (-1);
	}
	free_2d_array(map_copy);
	map[parser_s->start_pos_y][parser_s->start_pos_x] = '0';
	return (1);
}

int	texture_checks(char *line)
{
	const char	str[] = ".png";
	int			index;
	int			count;

	index = 0;
	count = 0;
	while (line[index])
		index++;
	if (index < 4)
		return (-1);
	count = 3;
	index--;
	while (count >= 0)
	{
		if (str[count] != line[index])
			return (-1);
		count--;
		index--;
	}
	return (1);
}

int	are_there_empty_inputs(t_parser *parser_s)
{
	if (!parser_s)
		return (-1);
	if (!parser_s->map)
		error_parser(parser_s, "Missing Map!");
	if (!parser_s->n_texture || texture_checks(parser_s->n_texture) == -1)
		error_parser(parser_s, "Missing North texture!");
	if (!parser_s->e_texture || texture_checks(parser_s->e_texture) == -1)
		error_parser(parser_s, "Missing East texture!");
	if (!parser_s->s_texture || texture_checks(parser_s->s_texture) == -1)
		error_parser(parser_s, "Missing South texture!");
	if (!parser_s->w_texture || texture_checks(parser_s->w_texture) == -1)
		error_parser(parser_s, "Missing West texture!");
	if (!parser_s->rgb_ceiling || rgb_checks(parser_s->rgb_ceiling) == -1)
		error_parser(parser_s, "Invalid Ceiling colours!");
	if (!parser_s->rgb_floor || rgb_checks(parser_s->rgb_floor) == -1)
		error_parser(parser_s, "Invalid Floor colours!");
	return (1);
}
