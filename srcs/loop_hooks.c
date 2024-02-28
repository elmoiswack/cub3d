#include "../includes/cub3d.h"
#include <math.h>

void	movement_hook(void *param)
{
	t_gamestruct	*game;

	game = (t_gamestruct *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement_backwards(param);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement_forward(param);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement_right(param);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement_left(param);
}

void	extra_features(void *param)
{
	t_gamestruct	*game;

	game = (t_gamestruct *) param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		free_game_struct(game);
		exit(0);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_M))
	{
		game->raycaster_img->enabled = false;
		disable_minimap(game->minimap);
		enable_fullmap(game->minimap);
	}
}

void	view_player_left(void *param)
{
	t_gamestruct	*game;
	double			old_dir_x;
	double			old_plane_x;
	double			rots;

	game = (t_gamestruct *) param;
	rots = game->mlx->delta_time * 4.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		old_dir_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * \
			cos(rots) - game->player->direction_y * sin(rots);
		game->player->direction_y = old_dir_x * \
			sin(rots) + game->player->direction_y * cos(rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * \
			cos(rots) - game->player->plane_y * sin(rots);
		game->player->plane_y = old_plane_x * \
			sin(rots) + game->player->plane_y * cos(rots);
		draw_screen(game);
	}
}

void	view_player_right(void *param)
{
	t_gamestruct	*game;
	double			old_dir_x;
	double			old_plane_x;
	double			rots;

	game = (t_gamestruct *) param;
	rots = game->mlx->delta_time * 4.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * \
			cos(-rots) - game->player->direction_y * sin(-rots);
		game->player->direction_y = old_dir_x * \
			sin(-rots) + game->player->direction_y * cos(-rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * \
			cos(-rots) - game->player->plane_y * sin(-rots);
		game->player->plane_y = old_plane_x * \
			sin(-rots) + game->player->plane_y * cos(-rots);
		draw_screen(game);
	}
}
