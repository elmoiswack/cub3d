#include "../../includes/cub3d.h"
#include <stdio.h>

void	mm_place_border(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_border, (x * mini->mm_scaler), (y * mini->mm_scaler));
}

//draws the walls onto the screen
void	mm_place_walls(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_wall, (x * mini->mm_scaler), (y * mini->mm_scaler));
}

//draws the floors onto the screen
void	mm_place_floors(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_floor, (x * mini->mm_scaler), (y * mini->mm_scaler));
}

//draws the player onto the screen
void	mm_place_player(t_minimap *mini, int x, int y)
{
	mlx_image_to_window(mini->mlx, mini->screen_player, x * mini->mm_scaler, y * mini->mm_scaler);
}