#include "../includes/cub3d.h"
#include <math.h>

int	player_hits_wall(t_gamestruct *game, int x, int y)
{
	return (game->map[y][x] == '1');
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
	move_speed = 0.15;
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
	move_speed = 0.15;
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
	move_speed = 0.15;
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
	move_speed = 0.15;
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

void	new_plane_calculator(t_gamestruct *game, bool towards_left, double rots)
{
	double			old_dir_x;
	double			old_plane_x;
	
	if (towards_left == true)
	{
		old_dir_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * cos(rots) - game->player->direction_y * sin(rots);
		game->player->direction_y = old_dir_x * sin(rots) + game->player->direction_y * cos(rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(rots) - game->player->plane_y * sin(rots);
		game->player->plane_y = old_plane_x * sin(rots) + game->player->plane_y * cos(rots);		
	}
	else
	{
		old_dir_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * cos(-rots) - game->player->direction_y * sin(-rots);
		game->player->direction_y = old_dir_x * sin(-rots) + game->player->direction_y * cos(-rots);
		old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(-rots) - game->player->plane_y * sin(-rots);
		game->player->plane_y = old_plane_x * sin(-rots) + game->player->plane_y * cos(-rots);		
	}
}

void	mouse_movement(void *param)
{
	t_gamestruct *game;
	int32_t	new_x;
	int32_t	new_y;
	int32_t	mouse_x;
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
			new_plane_calculator(game, true, rots);
		else
			new_plane_calculator(game, false, rots);
		draw_screen(game);
	}
	mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void	clean_map_array(t_gamestruct *game)
{
	int	index;
	int	x;

	index = 0;
	while (game->map[index])
	{
		x = ft_strlen(game->map[index]);
		x--;
		while (x > 0 && game->map[index][x] != '1')
			x--;
		if (game->map[index][x] == '1')
		{
			x++;
			game->map[index][x] = '\0';
		}
		index++;
	}
}

void	setup_game_variables(t_gamestruct *game, t_raycaster *player)
{
	game->player = player;
	set_vars_player(game->player);
	clean_map_array(game);
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!game->minimap)
		error_game(game, "Allocation of minimap failed!");
	set_vars_minimap(game);
	if (!game->raycaster_img)
	{
		game->raycaster_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx_image_to_window(game->mlx, game->raycaster_img, 0, 0);
	}
}

//this is the main start of the game
//the raycaster creates the line be drawn on the screen, this loop goes on untill you have cover the entire screen
//mlx_loop starts the game loop
void	start_game(t_gamestruct *game, t_raycaster *player)
{
	setup_game_variables(game, player);
	basic_raycaster(game);
	create_minimap(game->minimap);
	mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	mlx_loop_hook(game->mlx, &view_player, game);
	mlx_loop_hook(game->mlx, &extra_features, game);
	mlx_loop_hook(game->mlx, &mouse_movement, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
}
