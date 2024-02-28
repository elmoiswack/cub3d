#include "../../includes/cub3d.h"

void	error_parser( t_parser *parser_s, const char *str)
{
	printf("ERROR: %s\n", str);
	free_parser_struct(parser_s);
	exit(1);
}

void	error_convert(t_parser *parser, t_gamestruct *game, const char *str)
{
	if (parser)
		free_parser_struct(parser);
	if (game)
		free_game_struct(game);
	printf("ERROR: %s\n", str);
	exit(1);
}

void	error_game(t_gamestruct *game, const char *str)
{
	printf("ERROR: %s\n", str);
	free_game_struct(game);
	exit(1);
}
