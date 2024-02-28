#include "../../includes/cub3d.h"

void	delete_game_textures(t_gamestruct *game)
{
	if (game->north_textu)
		mlx_delete_texture(game->north_textu);
	game->north_textu = NULL;
	if (game->east_textu)
		mlx_delete_texture(game->east_textu);
	game->east_textu = NULL;
	if (game->south_textu)
		mlx_delete_texture(game->south_textu);
	game->south_textu = NULL;
	if (game->west_textu)
		mlx_delete_texture(game->west_textu);
	game->west_textu = NULL;
}

void	delete_game_images(t_gamestruct *game)
{
	if (game->north)
		mlx_delete_image(game->mlx, game->north);
	if (game->east)
		mlx_delete_image(game->mlx, game->east);
	if (game->west)
		mlx_delete_image(game->mlx, game->west);
	if (game->south)
		mlx_delete_image(game->mlx, game->south);
}

void	delete_fullmap(t_minimap *minimap)
{
	if (minimap->fullm_background)
	{
		mlx_delete_image(minimap->mlx, minimap->fullm_background);
		minimap->fullm_background = NULL;
	}
	if (minimap->fullm_floor)
	{
		mlx_delete_image(minimap->mlx, minimap->fullm_floor);
		minimap->fullm_floor = NULL;
	}
	if (minimap->fullm_player)
	{
		mlx_delete_image(minimap->mlx, minimap->fullm_player);
		minimap->fullm_player = NULL;
	}
	if (minimap->fullm_wall)
	{
		mlx_delete_image(minimap->mlx, minimap->fullm_wall);
		minimap->fullm_wall = NULL;
	}
}

void	delete_minimap(t_minimap *mini)
{
	if (mini->minimap_border)
	{
		mlx_delete_image(mini->mlx, mini->minimap_border);
		mini->minimap_border = NULL;
	}
	if (mini->minimap_image)
	{
		mlx_delete_image(mini->mlx, mini->minimap_image);
		mini->minimap_image = NULL;
	}
}
