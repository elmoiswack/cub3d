#include "../includes/cub3d.h"
#include <math.h>

void	new_plane_calc_left(t_gamestruct *game, double rots)
{
	double			old_dir_x;
	double			old_plane_x;

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
}

void	new_plane_calc_right(t_gamestruct *game, double rots)
{
	double			old_dir_x;
	double			old_plane_x;

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
}

void	mouse_movement(void *param)
{
	t_gamestruct	*game;
	int32_t			new_x;
	int32_t			new_y;
	int32_t			mouse_x;
	double			rots;

	game = param;
	rots = game->mlx->delta_time * 4.0;
	mouse_x = SCREEN_WIDTH / 2;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(game->mlx, &new_x, &new_y);
	if (mouse_x != new_x)
	{
		if (new_x > SCREEN_WIDTH)
			new_x = SCREEN_WIDTH;
		if (new_x < 0)
			new_x = 0;
		if (new_x < mouse_x)
			new_plane_calc_left(game, rots);
		else
			new_plane_calc_right(game, rots);
		draw_screen(game);
	}
	mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
