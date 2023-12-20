#include "../includes/cub3d.h"

t_gamestruct *texture_to_images(t_gamestruct *game, t_parser *parser)
{
	game->north = mlx_texture_to_image(game->mlx, game->north_textu);
	if (!game->north)
		error_convert(parser, game, "failed to convert northern texture to image!");
	game->east = mlx_texture_to_image(game->mlx, game->east_textu);
	if (!game->east)
		error_convert(parser, game, "failed to convert eastern texture to image!");
	game->south = mlx_texture_to_image(game->mlx, game->south_textu);
	if (!game->south)
		error_convert(parser, game, "failed to convert southern texture to image!");
	game->west = mlx_texture_to_image(game->mlx, game->west_textu);
	if (!game->west)
		error_convert(parser, game, "failed to convert western texture to image!");
	delete_textures(game);
	return (game);
}

t_gamestruct *getting_images(t_parser *parser, t_gamestruct *game)
{
	game->north_textu = mlx_load_png("./textures/kisspng-bert-ernie-elmo-big-bird-cookie-monster-wall-hole-5adfbb633b4e06.9805700015246119392429.png");
	if (!game->north_textu)
		error_convert(parser, game, "failed to load northern texture!");
	game->east_textu = mlx_load_png(parser->e_texture);
	if (!game->east_textu)
		error_convert(parser, game, "failed to load eastern texture!");
	game->south_textu = mlx_load_png(parser->s_texture);
	if (!game->south_textu)
		error_convert(parser, game, "failed to load southern texture!");
	game->west_textu = mlx_load_png(parser->w_texture);
	if (!game->west_textu)
		error_convert(parser, game, "failed to load western texture!");
	game = texture_to_images(game, parser);
	return (game);
}


t_gamestruct *convert_data(t_parser *parser_s, t_gamestruct *gamestruct)
{
	gamestruct->map = copy_2d_array(parser_s->map);
	gamestruct->start_x = parser_s->start_posx;
	gamestruct->start_y = parser_s->start_posy;
	gamestruct->start_direction = parser_s->start_direction;
	gamestruct->floor_rgb = ft_strdup(parser_s->rgb_floor);
	gamestruct->ceiling_rgb = ft_strdup(parser_s->rgb_ceiling);
	if (!gamestruct->ceiling_rgb || !gamestruct->floor_rgb)
		error_convert(parser_s, gamestruct, "failed to duplicate floor or ceiling colours!");
	return (gamestruct);
}
