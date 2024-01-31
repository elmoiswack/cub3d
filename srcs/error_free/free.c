#include "../../includes/cub3d.h"
#include "stdlib.h"

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

void	free_minimap_struct(t_minimap *mini)
{
	delete_minimap(mini);
	delete_fullmap(mini);
}

void	free_game_struct(t_gamestruct *game)
{
	if (!game)
		return ;
	delete_game_textures(game);
	delete_game_images(game);
	if (game->minimap)
		free_minimap_struct(game->minimap);
	free(game->minimap);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_2d_array(game->map);
	free(game->player);
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