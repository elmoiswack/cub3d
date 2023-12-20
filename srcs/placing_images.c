#include "../includes/cub3d.h"

bool is_placablechar(char c)
{
	if (c == ' ')
		return (false);
	if (valid_char(c) == 1)
		return (true);
	return (false);
}

char	which_char_toplace(char **map, int y, int x)
{
	if (x == 0 && valid_char(map[y][x + 1]) == 1)
		return ('W');
	if (x == (ft_strlen(map[y]) - 1) && valid_char(map[y][x - 1]) == 1)
		return ('E');
	if (y == 0 && valid_char(map[y + 1][x]) == 1)
		return ('N');
	if (y == (get_max_2d(map) - 1) && valid_char(map[y - 1][x]) == 1)
		return ('S');
	
}

void	placing_images(t_gamestruct *game)
{
	int	index;
	int	i;

	index = 0;
	while (game->map[index])
	{
		i = 0;
		while (game->map[index][i])
		{
			if (is_placablechar(game->map[index][i]) == true)
				place_image_onchar(game->map, index, i, which_char_toplace(game->map, index, i));

		}
		
	}
}