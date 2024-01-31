#include "../includes/cub3d.h"
#include <math.h>

int	player_hits_wall(t_gamestruct *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

void	draw_screen(t_gamestruct *game)
{
	if (game->minimap->fullmap_enabled == true)
		disable_fullmap(game->minimap);
	if (game->raycaster_img->enabled == false)
		game->raycaster_img->enabled = true;
	basic_raycaster(game);
	if (game->minimap->minimap_enabled == false)
		enable_minimap(game->minimap);
	create_minimap(game->minimap);	
}

//if a key is pressed and the conditions are met, the player posx or posy are changed
//because the player position has changed, we need to redraw the screen coherrently
//this will be done by the raycaster with the updated positions and the minimap
void 	movement_forward(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = game->mlx->delta_time * 5.0;
	new_pos_x = game->player->player_pos_x + (game->player->direction_x * move_speed);
	new_pos_y = game->player->player_pos_y + (game->player->direction_y * move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		new_pos_x = game->player->player_pos_x + (game->player->direction_x * move_speed);
		new_pos_y = game->player->player_pos_y + (game->player->direction_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x += (game->player->direction_x * move_speed);
			game->player->player_pos_y += (game->player->direction_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void 	movement_backwards(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = game->mlx->delta_time * 5.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		new_pos_x =  game->player->player_pos_x - (game->player->direction_x * move_speed);
		new_pos_y =  game->player->player_pos_y - (game->player->direction_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x -= (game->player->direction_x * move_speed);
			game->player->player_pos_y -= (game->player->direction_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void 	movement_right(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = game->mlx->delta_time * 5.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		new_pos_x  = game->player->player_pos_x + (game->player->plane_x * move_speed);
		new_pos_y =  game->player->player_pos_y + (game->player->plane_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x += (game->player->plane_x * move_speed);
			game->player->player_pos_y += (game->player->plane_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;
		draw_screen(game);
	}
}

void	movement_left(void *param)
{
	t_gamestruct	*game;
	double			move_speed;
	double			new_pos_x;
	double			new_pos_y;

	game = (t_gamestruct *)param;
	move_speed = game->mlx->delta_time * 5.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (game->minimap->fullmap_enabled == true)
			disable_fullmap(game->minimap);
		new_pos_x = game->player->player_pos_x - (game->player->plane_x * move_speed);
		new_pos_y = game->player->player_pos_y - (game->player->plane_y * move_speed);
		if (player_hits_wall(game, new_pos_x, new_pos_y) == 0)
		{
			game->player->player_pos_x -= (game->player->plane_x * move_speed);
			game->player->player_pos_y -= (game->player->plane_y * move_speed);
		}
		game->minimap->player_y = game->player->player_pos_y;
		game->minimap->player_x = game->player->player_pos_x;;
		draw_screen(game);
	}
}

void 	view_player(void *param)
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
		game->player->direction_x = game->player->direction_x * cos(rots) - game->player->direction_y * sin(rots);
		game->player->direction_y = old_dir_x * sin(rots) + game->player->direction_y * cos(rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(rots) - game->player->plane_y * sin(rots);
		game->player->plane_y = old_plane_x * sin(rots) + game->player->plane_y * cos(rots);
		draw_screen(game);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * cos(-rots) - game->player->direction_y * sin(-rots);
		game->player->direction_y = old_dir_x * sin(-rots) + game->player->direction_y * cos(-rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(-rots) - game->player->plane_y * sin(-rots);
		game->player->plane_y = old_plane_x * sin(-rots) + game->player->plane_y * cos(-rots);
		draw_screen(game);
	}
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

void	movement_hook(void *param)
{
	t_gamestruct *game;

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

//this is the main start of the game
//the raycaster creates the line be drawn on the screen, this loop goes on untill you have cover the entire screen
//mlx_loop starts the game loop
void	start_game(t_gamestruct *game, t_raycaster *player)
{
	game->player = player;
	set_vars_player(game->player);
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!game->minimap)
		error_game(game, "Allocation of minimap failed!");
	set_vars_minimap(game);
	if (!game->raycaster_img)
	{
		game->raycaster_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx_image_to_window(game->mlx, game->raycaster_img, 0, 0);
	}
	basic_raycaster(game);
	create_minimap(game->minimap);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	mlx_loop_hook(game->mlx, &view_player, game);
	mlx_loop_hook(game->mlx, &extra_features, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
}