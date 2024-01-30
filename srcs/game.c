#include "../includes/cub3d.h"

//if a key is pressed and the conditions are met, the player posx or posy are changed
//because the player position has changed, we need to redraw the screen coherrently
//this will be done by the raycaster with the updated positions and the minimap
void 	movement_player(void *param)
{
	t_gamestruct *game;

	game = (t_gamestruct *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && (game->map[(int)(game->player->player_posy - 0.5)][(int)(game->player->player_posx)] != '1'))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		game->raycaster_img->enabled = true;
		game->player->player_posy -= 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		if (game->minimap->minimap_enabled == false)
			enable_minimap(game->minimap);
		create_minimap(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx + 0.5)] != '1'))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		game->raycaster_img->enabled = true;
		game->player->player_posx += 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		if (game->minimap->minimap_enabled == false)
			enable_minimap(game->minimap);
		create_minimap(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && (game->map[(int)(game->player->player_posy + 0.5)][(int)(game->player->player_posx)] != '1'))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		game->raycaster_img->enabled = true;
		game->player->player_posy += 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		if (game->minimap->minimap_enabled == false)
			enable_minimap(game->minimap);
		create_minimap(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && (game->map[(int)(game->player->player_posy)][(int)(game->player->player_posx - 0.5)] != '1'))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		game->raycaster_img->enabled = true;
		game->player->player_posx -= 0.2;
		game->minimap->player_y = game->player->player_posy;
		game->minimap->player_x = game->player->player_posx;
		basic_raycaster(game, game->player);
		if (game->minimap->minimap_enabled == false)
			enable_minimap(game->minimap);
		create_minimap(game->minimap);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
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

//this is the main start of the game
//the raycaster creates the line be drawn on the screen, this loop goes on untill you have cover the entire screen
//mlx_loop starts the game loop

void	start_game(t_gamestruct *game, t_playerinfo *player)
{
	game->player = player;
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!game->minimap)
		error_game(game, "Allocation of minimap failed!");
	set_vars_minimap(game);
	create_fullmap(game->minimap);
	basic_raycaster(game, game->player);
	create_minimap(game->minimap);
	mlx_loop_hook(game->mlx, &movement_player, game);
	mlx_loop(game->mlx);
}