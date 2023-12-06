#include "../includes/cub3d.h"
#include "stdio.h"



t_parser *parser_checks(t_parser *parser_s)
{
	if (map_checker(parser_s->map, parser_s) == -1)
		return (error_parser(parser_s, "Invalid map"), NULL);
	return (parser_s);
}