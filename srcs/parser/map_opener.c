#include "../includes/cub3d.h"
#include <fcntl.h>

int	check_argv(char **argv)
{
	const char str[] = "buc.";
	int	index_str;
	int	index_arg;

	index_str = 3;
	index_arg = ft_strlen(argv[1]);
	while (argv[1][index_arg] && index_str >= 0)
	{
		if (argv[1][index_arg] != str[index_str])
			return (-1);
		index_arg--;
		index_str--;	
	}
	return (1);
}

char	*gnl_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;
	
	ptr =  ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	free(s1);
	return (ptr);
}

char	*get_content_into_line(int fd)
{
	char	*gnl_line;
	char	*full;

	gnl_line = get_next_line(fd);
	if (!gnl_line)
		return (NULL);
	full = ft_calloc(1, sizeof(char));
	if (!full)
		return (NULL);
	while (gnl_line)
	{
		full = gnl_join(full, gnl_line);
		if (!full)
		{
			free(gnl_line);
			return (NULL);
		}
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	return (full);
}

char	**get_content_map(int fd)
{
	char	*full_line;
	char	**array;

	full_line = get_content_into_line(fd);
	if (!full_line)
		return (NULL);
	array = ft_split(full_line, '\n');
	if (!array)
		return (NULL);
	return (array);
}

t_parser *get_info_map(t_parser *parser_s, char *argv[])
{
	int	fd;
	
	if (check_argv(argv) == -1)
		return (error_parser(parser_s, "map doesn't end with .cub"), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_parser(parser_s, "file couldn't be opened"), NULL);
	parser_s->full_file = get_content_map(fd);
	close(fd);
	if (!parser_s->full_file)
		return (error_parser(parser_s, "getting the maps content failed"), NULL);
	return (parser_s);
}