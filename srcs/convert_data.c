#include "../includes/cub3d.h"

t_gamestruct	*texture_to_images(t_gamestruct *game, t_parser *parser)
{
	game->north = mlx_texture_to_image(game->mlx, game->north_textu);
	if (!game->north)
		error_convert(parser, game, "failed to convert northern \
			texture to image!");
	game->east = mlx_texture_to_image(game->mlx, game->east_textu);
	if (!game->east)
		error_convert(parser, game, "failed to convert eastern \
			texture to image!");
	game->south = mlx_texture_to_image(game->mlx, game->south_textu);
	if (!game->south)
		error_convert(parser, game, "failed to convert southern \
			texture to image!");
	game->west = mlx_texture_to_image(game->mlx, game->west_textu);
	if (!game->west)
		error_convert(parser, game, "failed to convert western \
			texture to image!");
	delete_game_textures(game);
	return (game);
}

static void	load_textures(t_gamestruct *game, t_parser *parse)
{
	game->north_textu = mlx_load_png(parse->n_texture);
	if (!game->north_textu)
		error_convert(parse, game, "failed to load northern \
			texture!");
	game->east_textu = mlx_load_png(parse->e_texture);
	if (!game->east_textu)
		error_convert(parse, game, "failed to load eastern \
			texture!");
	game->south_textu = mlx_load_png(parse->s_texture);
	if (!game->south_textu)
		error_convert(parse, game, "failed to load southern \
			texture!");
	game->west_textu = mlx_load_png(parse->w_texture);
	if (!game->west_textu)
		error_convert(parse, game, "failed to load western \
			texture!");
}

t_gamestruct	*convert_data(t_parser *parser_s, \
	t_gamestruct *gamestruct, t_raycaster *player)
{
	gamestruct->map = copy_2d_array(parser_s->map);
	player->player_pos_x = parser_s->start_pos_x + 0.5;
	player->player_pos_y = parser_s->start_pos_y + 0.5;
	player->start_direction = parser_s->start_direction;
	gamestruct->floor_rgb = parser_s->rgb_floor_int;
	gamestruct->ceiling_rgb = parser_s->rgb_ceiling_int;
	load_textures(gamestruct, parser_s);
	return (gamestruct);
}
