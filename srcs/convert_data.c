#include "../includes/cub3d.h"

//converts all the textures we have into usable images for mlx
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

//loading all paths of the textures we got from the parser and puts them into a mlx_texture_t in the game_struct
t_gamestruct *getting_images(t_parser *parser, t_gamestruct *game)
{
	game->north_textu = mlx_load_png(parser->n_texture);
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

//puts everything that we gathered from the parser into the gamestruct and playerstruct
t_gamestruct *convert_data(t_parser *parser_s, t_gamestruct *gamestruct, t_playerinfo *player)
{
	gamestruct->map = copy_2d_array(parser_s->map);
	player->player_posx = parser_s->start_posx;
	player->player_posy = parser_s->start_posy;
	player->start_direction = parser_s->start_direction;
	gamestruct->floor_rgb = parser_s->rgb_floor_int;
	gamestruct->ceiling_rgb = parser_s->rgb_ceiling_int;
	return (gamestruct);
}
