#include "../../includes/cub3d.h"

void	calculate_fm_scaler(t_minimap *mini)
{
	int	line_width;
	int	line_height;
	int	divider;

	if (SCREEN_WIDTH > SCREEN_HEIGHT)
		divider = SCREEN_WIDTH;
	else
		divider = SCREEN_HEIGHT;
	line_width = get_size_biggest_line(mini->file_map);
	line_height = get_max_2d(mini->file_map);
	if (line_width > line_height)
		mini->fm_scaler = divider / line_width;
	else
		mini->fm_scaler = divider / line_height;
	mini->fm_offset = (SCREEN_HEIGHT / 2) - \
		((get_max_2d(mini->file_map) / 2) * mini->fm_scaler);
}

void	set_vars_minimap(t_gamestruct *game)
{
	game->minimap->game = game;
	game->minimap->file_map = game->map;
	game->minimap->mlx = game->mlx;
	game->minimap->player_y = game->player->player_pos_y;
	game->minimap->player_x = game->player->player_pos_x;
	game->minimap->minimap_enabled = true;
	game->minimap->fullmap_enabled = false;
	game->minimap->mm_scaler = MINIMAP_WIDTH / 6;
	calculate_fm_scaler(game->minimap);
	create_fullmap(game->minimap);
}
