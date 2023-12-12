#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_parser *parser_s;

	if (argc != 2)
	{
		printf("Only one additional argument is excepted as input. ./cub3d 'path to the mapfile'\n");
		exit (1);
	}
	parser_s = ft_calloc(1, sizeof(t_parser));
	if (!parser_s)
		error_parser(parser_s, "allocation of mainstruct failed");
	parser_s = parser(parser_s, argv);
	return (0);
}

