#include "../../includes/cub3d.h"
#include "stdlib.h"

void	delete_textures(t_gamestruct *game)
{
	mlx_delete_texture(game->north_textu);
	game->north_textu = NULL;
	mlx_delete_texture(game->east_textu);
	game->east_textu = NULL;
	mlx_delete_texture(game->south_textu);
	game->south_textu = NULL;
	mlx_delete_texture(game->west_textu);
	game->west_textu = NULL;
}

void	free_2d_array(char	**array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_game_struct(t_gamestruct *game)
{
	if (!game)
		return ;
	delete_textures(game);
	if (game->north)
		mlx_delete_image(game->mlx, game->north);
	if (game->east)
		mlx_delete_image(game->mlx, game->east);
	if (game->west)
		mlx_delete_image(game->mlx, game->west);
	if (game->south)
		mlx_delete_image(game->mlx, game->south);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_2d_array(game->map);
	if (game->floor_rgb)
		free(game->floor_rgb);
	if (game->ceiling_rgb)
		free(game->ceiling_rgb);
	free(game);
}

void	free_parser_struct(t_parser *parser_s)
{
	if (!parser_s)
		return ;
	if (parser_s->full_file)
		free_2d_array(parser_s->full_file);
	if (parser_s->map)
		free_2d_array(parser_s->map);
	if (parser_s->n_texture)
		free(parser_s->n_texture);
	if (parser_s->e_texture)
		free(parser_s->e_texture);
	if (parser_s->s_texture)
		free(parser_s->s_texture);
	if (parser_s->w_texture)
		free(parser_s->w_texture);
	if (parser_s->rgb_floor)
		free(parser_s->rgb_floor);
	if (parser_s->rgb_ceiling)
		free(parser_s->rgb_ceiling);
	free(parser_s);
}