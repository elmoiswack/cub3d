/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:14:48 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:14:50 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	draw_screen(t_gamestruct *game)
{
	if (game->minimap->fullmap_enabled == true)
		disable_fullmap(game->minimap);
	if (game->raycaster_img->enabled == false)
		game->raycaster_img->enabled = true;
	raycaster(game, 0);
	if (game->minimap->minimap_enabled == false)
		enable_minimap(game->minimap);
	game->minimap->player_y = game->player->player_pos_y;
	game->minimap->player_x = game->player->player_pos_x;
	create_minimap(game->minimap);
}

//this is the main start of the game
//the raycaster creates the line be drawn on the screen, 
//this loop goes on untill you have cover the entire screen
//mlx_loop starts the game loop
void	start_game(t_gamestruct *game, t_raycaster *player)
{
	setup_game_variables(game, player);
	raycaster(game, 0);
	create_minimap(game->minimap);
	mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	mlx_loop_hook(game->mlx, &view_player_left, game);
	mlx_loop_hook(game->mlx, &view_player_right, game);
	mlx_loop_hook(game->mlx, &extra_features, game);
	mlx_loop_hook(game->mlx, &mouse_movement, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
}
