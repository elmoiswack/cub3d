#include "../includes/cub3d.h"

void 	movement_player(void *param)
{
	t_gamestruct *game;

	game = (t_gamestruct *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && (game->map[(int)(game->player->player_posy - 0.8)][(int)(game->player->player_posx)] != '1'))
	{
		game->player->player_posy -= 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		mm_make_player(game->minimap);
		mm_place_player(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx + 0.3)] != '1'))
	{
		game->player->player_posx += 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		mm_make_player(game->minimap);
		mm_place_player(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && (game->map[(int)(game->player->player_posy + 0.3)][(int)(game->player->player_posx)] != '1'))
	{
		game->player->player_posy += 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		mm_make_player(game->minimap);
		mm_place_player(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx - 0.8)] != '1'))
	{
		game->player->player_posx -= 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		mm_make_player(game->minimap);
		mm_place_player(game->minimap);
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
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!game->minimap)
		error_game(game, "Allocation of minimap failed!");
	game->minimap->file_map = game->map;
	game->minimap->mlx = game->mlx;
	game->minimap->player_y = game->player->player_posy;
	game->minimap->player_x = game->player->player_posx;
	minimap(game->minimap);
	mlx_loop_hook(game->mlx, &movement_player, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);

}