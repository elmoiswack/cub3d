#include "../includes/cub3d.h"
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
t_parser *parser(t_parser *parser_s, char *argv[])
{
	parser_s = get_info_map(parser_s, argv);
	parser_s = sort_content(parser_s);
	parser_s = parser_checks(parser_s);
	print_parser(parser_s);
	error_parser(parser_s, "\n");
	return (parser_s);
}