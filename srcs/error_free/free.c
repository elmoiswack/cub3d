#include "../includes/cub3d.h"
#include "stdlib.h"

void	free_2d_array(char	**array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_parser_struct(t_parser *parser_s)
{
	if (parser_s->full_file)
		free_2d_array(parser_s->full_file);
	if (parser_s->map)
		free_2d_array(parser_s->map);
	free(parser_s->n_texture);
	free(parser_s->e_texture);
	free(parser_s->s_texture);
	free(parser_s->w_texture);
	free(parser_s->rgb_floor);
	free(parser_s->rgb_ceiling);
	free(parser_s);
}