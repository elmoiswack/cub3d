#include "../../includes/cub3d.h"
#include "stdio.h"

//the floodfill algorithm
//it goes to every square that is allowed to go to
//if it goes to a square that shouldn't be reachable it returns -1 and an error is thrown
//else it goes on untill it has no squares to go to and returns 1
int	floodfill(char	**map, int start_x, int start_y)
{
	if ((start_x <= 0) || (start_y <= 0) || (start_x >= (int)ft_strlen(map[start_y]) - 2) 
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

//the main of the map checks, these are all the ft's used to check the map
int	map_checker(char **map, t_parser *parser_s)
{
	char	**map_copy;
	
	if (check_howmany_start(map) == -1)
		error_parser(parser_s, "Only 1 start position is needed, either an 'N', 'E', 'S' or 'W'!");
	if (check_char_map(map) == -1)
		error_parser(parser_s, "An invalid character is inside the map!");
	if (border_check(map) == -1)
		error_parser(parser_s, "Unclosed borders!");
	get_start_pos(map, &parser_s->start_pos_x, &parser_s->start_pos_y, &parser_s->start_direction);
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

//the main of the rgb checks, these are all the ft's used to check if the rgb values given are valid
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

int	alpha_in_texture(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	//say for example our evaluator changes the directory and the names of the textures to only numbers this ft would fail, should i change it or nah?
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

//safety check to see if there are any empty input
//if so, error is thrown because we need all of them to run cub3d
int	are_there_empty_inputs(t_parser *parser_s)
{
	if (!parser_s)
		return (-1);
	if (!parser_s->map)
		error_parser(parser_s, "Missing Map!");
	if (!parser_s->n_texture || alpha_in_texture(parser_s->n_texture) == -1)
		error_parser(parser_s, "Missing North texture!");
	if (!parser_s->e_texture || alpha_in_texture(parser_s->e_texture) == -1)
		error_parser(parser_s, "Missing East texture!");
	if (!parser_s->s_texture || alpha_in_texture(parser_s->s_texture) == -1)
		error_parser(parser_s, "Missing South texture!");
	if (!parser_s->w_texture || alpha_in_texture(parser_s->w_texture) == -1)
		error_parser(parser_s, "Missing West texture!");
	if (!parser_s->rgb_ceiling || rgb_checks(parser_s->rgb_ceiling) == -1)
		error_parser(parser_s, "Invalid Ceiling colours!");
	if (!parser_s->rgb_floor || rgb_checks(parser_s->rgb_floor) == -1)
		error_parser(parser_s, "Invalid Floor colours!");
	return (1);
}
