#include "../includes/cub3d.h"

int	get_max_2d(char **array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}

char	**copy_2d_array(char **array)
{
	char	**new;
	int		index;

	index = get_max_2d(array);
	new = ft_calloc(index + 1, sizeof(char *));
	if (!new)
		return (NULL);
	index = 0;
	while (array[index])
	{
		new[index] = ft_calloc(ft_strlen(array[index]) + 1, sizeof(char));
		if (!new[index])
			return (free_2d_array(new), NULL);
		ft_strlcpy(new[index], array[index], ft_strlen(array[index]) + 1);
		index++;
	}
	new[index] = NULL;
	return (new);
}