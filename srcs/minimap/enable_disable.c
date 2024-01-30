#include "../../includes/cub3d.h"

void	enable_minimap(t_minimap *mini)
{
	mini->screen_border->enabled = true;
	mini->screen_floor->enabled = true;
	mini->screen_player->enabled = true;
	mini->screen_wall->enabled = true;
	mini->minimap_enabled = true;
}

void	disable_minimap(t_minimap *mini)
{
	mini->screen_border->enabled = false;
	mini->screen_floor->enabled = false;
	mini->screen_player->enabled = false;
	mini->screen_wall->enabled = false;
	mini->minimap_enabled = false;
}

void	disable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = false;
	mini->fullm_floor->enabled = false;
	mini->fullm_wall->enabled = false;
	mini->fullm_player->enabled = false;
	mini->fullmap_enabled = false;
}

void	enable_fullmap(t_minimap *mini)
{
	mini->fullm_background->enabled = true;
	mini->fullm_floor->enabled = true;
	mini->fullm_wall->enabled = true;
	mini->fullm_player->enabled = true;
	mini->fullm_player->instances->x = mini->player_x * mini->fm_scaler;
	mini->fullm_player->instances->y = mini->player_y * mini->fm_scaler + mini->fm_offset;
	mini->fullmap_enabled = true;
}