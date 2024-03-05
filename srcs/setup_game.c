/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:15:05 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:15:06 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

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
		game->raycaster_img = mlx_new_image(game->mlx, \
			SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx_image_to_window(game->mlx, game->raycaster_img, 0, 0);
	}
}
