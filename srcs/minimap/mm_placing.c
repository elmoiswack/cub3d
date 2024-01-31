#include "../../includes/cub3d.h"
#include <stdio.h>

void	mm_place_border(t_minimap *mini, int x, int y)
{
	if (mlx_image_to_window(mini->mlx, mini->screen_border, (x * mini->mm_scaler + 30), (y * mini->mm_scaler + 30)) == -1)
		error_game(mini->game, "Failed to place the border mm!");
}

//draws the walls onto the screen
void	mm_place_walls(t_minimap *mini, int x, int y)
{
	if (mlx_image_to_window(mini->mlx, mini->screen_wall, (x * mini->mm_scaler + 30), (y * mini->mm_scaler + 30)) == -1)
		error_game(mini->game, "Failed to place the walls mm!");
}

//draws the floors onto the screen
void	mm_place_floors(t_minimap *mini, int x, int y)
{
	if (mlx_image_to_window(mini->mlx, mini->screen_floor, (x * mini->mm_scaler + 30), (y * mini->mm_scaler + 30)) == -1)
		error_game(mini->game, "Failed to place the floors mm!");
}

//draws the player onto the screen
void	mm_place_player(t_minimap *mini, int x, int y)
{
	if (mlx_image_to_window(mini->mlx, mini->screen_player, x * mini->mm_scaler + 30, y * mini->mm_scaler + 30) == -1)
		error_game(mini->game, "Failed to place the player mm!");
}

void	place_minimap_border(t_minimap *mini)
{
	if (mlx_image_to_window(mini->mlx, mini->mm_border, 0, 0) == -1)
		error_game(mini->game, "Failed to place the border surrounding the minimap mm!");
}