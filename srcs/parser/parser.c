#include "../../includes/cub3d.h"
#include "stdio.h"

t_parser	*parser_checks(t_parser *parser_s)
{
	if (are_there_empty_inputs(parser_s) == -1)
		error_parser(parser_s, "Missing important information from the file");
	if (map_checker(parser_s->map, parser_s) == -1)
		error_parser(parser_s, "The map inside the file is invalid!");
	return (parser_s);
}

uint32_t	transfer_colour_texture(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	transfer_colour(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	transfer_rgb_to_int(char *rgb)
{
	int		r;
	int		g;
	int		b;
	char	**temp;

	temp = ft_split(rgb, ',');
	if (!temp)
		return (-1);
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	free_2d_array(temp);
	return (transfer_colour(r, g, b));
}

t_parser	*parser(t_parser *parser_s, char *argv[])
{
	parser_s = get_info_file(parser_s, argv);
	parser_s = sort_content(parser_s);
	parser_s = parser_checks(parser_s);
	parser_s->rgb_floor_int = transfer_rgb_to_int(parser_s->rgb_floor);
	parser_s->rgb_ceiling_int = transfer_rgb_to_int(parser_s->rgb_ceiling);
	if (parser_s->rgb_ceiling_int == (uint32_t)-1 \
		|| parser_s->rgb_floor_int == (uint32_t)-1)
		error_parser(parser_s, "Failed to transfer rgb to uint");
	return (parser_s);
}
