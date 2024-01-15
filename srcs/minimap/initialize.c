#include "../../includes/cub3d.h"

int	get_size_biggest_line(char **map)
{
	int	y;
	int	size;
	
	y = 0;
	size = (int)ft_strlen(map[y]);
	y++;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) > size)
			size = (int)ft_strlen(map[y]);
		y++;
	}
	return (size - 1);
}

void	calculate_fm_scaler(t_minimap *mini)
{
	int	line_width;
	int	line_height;
	int divider;

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
	mini->fm_offset = (SCREEN_HEIGHT / 2) - ((get_max_2d(mini->file_map) / 2) * mini->fm_scaler);
}

void	calculate_mm_scaler(t_minimap *mini)
{
	int	line_width;
	int	line_height;
	int divider;

	if (MINIMAP_WIDTH > MINIMAP_HEIGHT)
		divider = MINIMAP_WIDTH;
	else
		divider = MINIMAP_HEIGHT;
	line_width = 6;
	line_height = 6;
	if (line_width > line_height)
		mini->mm_scaler = divider / line_width;
	else
		mini->mm_scaler = divider / line_height;
}

void	set_vars_minimap(t_gamestruct *game)
{
	game->minimap->file_map = game->map;
	game->minimap->mlx = game->mlx;
	game->minimap->player_y = game->player->player_posy;
	game->minimap->player_x = game->player->player_posx;
	game->minimap->minimap_enabled = true;
	game->minimap->fullmap_enabled = false;
	calculate_mm_scaler(game->minimap);
	calculate_fm_scaler(game->minimap);
}