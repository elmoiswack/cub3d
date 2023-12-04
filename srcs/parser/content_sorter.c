#include "../includes/cub3d.h"
#include "stdio.h"

char	*line_into_struct(char	*line, t_parser *parser_s)
{
	char	*new_line;
	int		index_new;
	int		index;

	index = 0;
	index_new = 0;
	new_line = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (!new_line)
		return (error_parser(parser_s, "allocation of line_into_struct failed"), NULL);
	while (line[index] && (ft_isalpha(line[index]) || line[index] == ' '))
		index++;
	while (line[index])
	{
		new_line[index_new] = line[index];
		index++;
		index_new++;
	}
	return (new_line);
}

t_parser *get_textures_rgb_path(t_parser *parser_s)
{
	int	index;

	index = 0;
	while (parser_s->full_file[index])
	{
		if (ft_strncmp(parser_s->full_file[index], "NO", 2) == 0)
			parser_s->n_texture = line_into_struct(parser_s->full_file[index], parser_s);
		else if (ft_strncmp(parser_s->full_file[index], "SO", 2) == 0)
			parser_s->s_texture = line_into_struct(parser_s->full_file[index], parser_s);
		else if (ft_strncmp(parser_s->full_file[index], "WE", 2) == 0)
			parser_s->w_texture = line_into_struct(parser_s->full_file[index], parser_s);
		else if (ft_strncmp(parser_s->full_file[index], "EA", 2) == 0)
			parser_s->e_texture = line_into_struct(parser_s->full_file[index], parser_s);
		else if (ft_strncmp(parser_s->full_file[index], "F", 1) == 0)
			parser_s->rgb_floor = line_into_struct(parser_s->full_file[index], parser_s);
		else if (ft_strncmp(parser_s->full_file[index], "C", 1) == 0)
			parser_s->rgb_ceiling = line_into_struct(parser_s->full_file[index], parser_s);
		index++;
	}
	return (parser_s);
}

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

t_parser *get_map(t_parser *parser_s , int index)
{
	int	count;
	int	i;

	i = 0;
	count = index;
	while (parser_s->full_file[count])
		count++;
	parser_s->map = ft_calloc((count - index) + 1, sizeof(char *));
	if (!parser_s->map)
		return (error_parser(parser_s, "allocation of map failed"), NULL);
	while (parser_s->full_file[index])
	{
		parser_s->map[i] = ft_calloc(ft_strlen(parser_s->full_file[index]) + 2, sizeof(char));
		if (!parser_s->map[i])
			return (error_parser(parser_s, "allocation and filling map failed"), NULL);
		ft_strlcpy(parser_s->map[i], parser_s->full_file[index], ft_strlen(parser_s->full_file[index]) + 1);
		i++;
		index++;
	}
	parser_s->map[i] = NULL;
	return (parser_s);
}

t_parser *sort_content(t_parser *parser_s)
{
	int	index;

	parser_s = get_textures_rgb_path(parser_s);
	if (!parser_s)
		return (error_parser(parser_s, "getting textures failed"), NULL);
	index = get_start_map(parser_s);
	if (index == -1)
		return (error_parser(parser_s, "failed to get the map"), NULL);
	parser_s = get_map(parser_s, index);
	return (parser_s);
}