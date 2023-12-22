#include "../includes/cub3d.h"

t_playerinfo *set_vars_player(t_playerinfo *player)
{
	player->directionx = -1;
	player->directiony = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (player);
}	

void	basic_raycaster(t_gamestruct *game, t_playerinfo *player)
{
	int	index;

	index = 0;
	player = set_vars_player(player);
	mlx_loop(game->mlx);
	while (index < SCREEN_WIDTH)
	{
		player->camerax = 2 * index / (double)SCREEN_WIDTH - 1;
		player->raydir_x = player->directionx + player->plane_x * player->camerax;
		player->raydir_y = player->directiony + player->plane_y * player->camerax;
		index++;
	}
	sleep(50000000);
	return ;
}