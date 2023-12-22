#include "../../includes/cub3d.h"

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