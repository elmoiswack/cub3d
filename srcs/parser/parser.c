#include "../../includes/cub3d.h"
#include "stdio.h"

void	print_parser(t_parser *parser_s)
{
	int	j = 0;

	printf("NO = %s\n", parser_s->n_texture);
	printf("SO = %s\n", parser_s->s_texture);
	printf("EA = %s\n", parser_s->e_texture);
	printf("WE = %s\n", parser_s->w_texture);
	printf("C = %s\n", parser_s->rgb_ceiling);
	printf("F = %s\n", parser_s->rgb_floor);
	printf("\n");
	if (parser_s->map)
	{
		printf("MAP\n");
		while (parser_s->map[j])
		{
			printf("%s", parser_s->map[j]);
			j++;
		}
	}
	return ;
}

t_parser *parser_checks(t_parser *parser_s)
{
	if (are_there_empty_inputs(parser_s) == -1)
		error_parser(parser_s, "Missing important information");
	if (map_checker(parser_s->map, parser_s) == -1)
		error_parser(parser_s, "Invalid map");
	return (parser_s);
}

int	transfer_colour(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	transfer_rgb_to_int(char *rgb)
{
	int	r;
	int	g;
	int	b;
	char	**temp;

	temp = ft_split(rgb, ',');
	if (!temp)
		return (0);
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	free_2d_array(temp);
	return (transfer_colour(r, g, b));
}

t_parser *parser(t_parser *parser_s, char *argv[])
{
	parser_s = get_info_map(parser_s, argv);
	parser_s = sort_content(parser_s);
	parser_s = parser_checks(parser_s);
	parser_s->rgb_floor_int = transfer_rgb_to_int(parser_s->rgb_floor);
	parser_s->rgb_ceiling_int = transfer_rgb_to_int(parser_s->rgb_ceiling);
	if (parser_s->rgb_ceiling_int == 0 || parser_s->rgb_floor_int == 0 )
		error_parser(parser_s, "failed to transfer rgb to uint");
	//print_parser(parser_s);
	return (parser_s);
}