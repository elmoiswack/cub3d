/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:14:38 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:14:39 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

void	draw_wall(t_gamestruct *game, mlx_texture_t *texture, int x)
{
	uint32_t	text_color;
	int			y;

	y = game->player->draw_start;
	game->player->step = 1.0 * texture->height / game->player->line_height;
	game->player->texture_pos = (game->player->draw_start - SCREEN_HEIGHT / 2 + \
		game->player->line_height / 2) * game->player->step;
	while (y < game->player->draw_end)
	{
		game->player->texture_y = \
			(int)game->player->texture_pos & (texture->height - 1);
		game->player->texture_pos += game->player->step;
		text_color = get_pixel_from_texture(texture, game->player->texture_x, \
			game->player->texture_y, 0);
		mlx_put_pixel(game->raycaster_img, x, y, text_color);
		y++;
	}
}

void	draw_ceiling_floor(t_gamestruct *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				mlx_put_pixel(game->raycaster_img, x, y, game->ceiling_rgb);
			else
				mlx_put_pixel(game->raycaster_img, x, y, game->floor_rgb);
			x++;
		}
		y++;
	}
}

uint32_t	get_pixel_from_texture(mlx_texture_t *texture, \
	double x_mult, double y_mult, int int_x_mult)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		int_y_mult;

	int_y_mult = (int) y_mult;
	int_x_mult = (int) x_mult;
	r = texture->pixels[(int_y_mult * texture->width + int_x_mult) * \
		texture->bytes_per_pixel];
	g = texture->pixels[(int_y_mult * texture->width + int_x_mult) * \
		texture->bytes_per_pixel + 1];
	b = texture->pixels[(int_y_mult * texture->width + int_x_mult) * \
		texture->bytes_per_pixel + 2];
	a = texture->pixels[(int_y_mult * texture->width + int_x_mult) * \
		texture->bytes_per_pixel + 3];
	return (transfer_colour_texture(r, g, b, a));
}

mlx_texture_t	*put_texture(t_gamestruct *game, mlx_texture_t *current_texture)
{
	if (game->player->side == 1 && game->player->raydir_y > 0)
		current_texture = game->north_textu;
	else if (game->player->side == 1 && game->player->raydir_y < 0)
		current_texture = game->south_textu;
	else if (game->player->side == 0 && game->player->raydir_x > 0)
		current_texture = game->west_textu;
	else if (game->player->side == 0 && game->player->raydir_x < 0)
		current_texture = game->east_textu;
	return (current_texture);
}
