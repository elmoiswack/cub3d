#include "../../includes/cub3d.h"
#include "stdio.h"

//checks of there is a r, g and a b value and seperated by a ','
//if not, the rgb value is invalid and -1 is returned
int	ammount_input_rgb(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] == ',')
			count++;
		index++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

//checks if the line passed isn't bigger than max int
//if it is, this ft will find it and returns -1
int	overflow_check(char *line)
{
	int		index;
	char	*str;

	index = 1;
	if (ft_strlen(line) > 10)
		return (-1);
	if (ft_strlen(line) < 10)
		return (1);
	str = malloc(11 * sizeof(char));
	if (!str)
		return (-1);
	ft_strlcpy(str, "2147483647", ft_strlen("2147483647"));
	while (line[index] && line[index] != '\n')
	{
		if (line[index] > str[index])
		{
			free(str);
			return (-1);
		}
		index++;
	}
	free(str);
	return (1);
}
