#include "../includes/cub3d.h"

void	error_parser( t_parser *parser_s, const char *str)
{
	printf("%s\n", str);
	free_parser_struct(parser_s);
	exit(1);
}