#include "../includes/cub3d.h"

t_parser	*start_parsing(int argc, char *argv[])
{
	t_parser		*parser_s;

	if (argc != 2)
	{
		printf("Only one additional argument is excepted as input: \
			./cub3d 'path to the mapfile'\n");
		exit (1);
	}
	parser_s = ft_calloc(1, sizeof(t_parser));
	if (!parser_s)
		error_parser(parser_s, "allocation of mainstruct failed");
	parser_s = parser(parser_s, argv);
	return (parser_s);
}

int	main(int argc, char *argv[])
{
	t_parser		*parser_s;
	t_gamestruct	*gamestruct;
	t_raycaster		*player;

	parser_s = start_parsing(argc, argv);
	gamestruct = ft_calloc(1, sizeof(t_gamestruct));
	if (!gamestruct)
		error_parser(parser_s, "failed to allocate gamestruct!");
	player = ft_calloc(1, sizeof(t_raycaster));
	if (!player)
		error_convert(parser_s, gamestruct, \
			"failed to allocate player struct!");
	gamestruct = convert_data(parser_s, gamestruct, player);
	free_parser_struct(parser_s);
	gamestruct->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	if (!gamestruct->mlx)
		error_convert(parser_s, gamestruct, "failed to initialize mlx!");
	start_game(gamestruct, player);
	free_game_struct(gamestruct);
	return (0);
}
