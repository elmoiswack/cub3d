#include "../includes/cub3d.h"

void 	movement_player(void *param)
{
	t_gamestruct *game;

	game = (t_gamestruct *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && (game->map[(int)(game->player->player_posy - 0.3)][(int)(game->player->player_posx)] != '1'))
	{
		game->player->player_posy -= 0.2;
		basic_raycaster(game, game->player);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx + 0.3)] != '1'))
	{
		game->player->player_posx += 0.2;
		basic_raycaster(game, game->player);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && (game->map[(int)(game->player->player_posy + 0.3)][(int)(game->player->player_posx)] != '1'))
	{
		game->player->player_posy += 0.2;
		basic_raycaster(game, game->player);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx - 0.3)] != '1'))
	{
		game->player->player_posx -= 0.2;
		basic_raycaster(game, game->player);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		free_game_struct(game);
		exit(0);
	}
}

void	start_game(t_gamestruct *game, t_playerinfo *player)
{
	game->player = player;
	basic_raycaster(game, game->player);
	mlx_loop_hook(game->mlx, &movement_player, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);

}