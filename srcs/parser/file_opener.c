#include "../../includes/cub3d.h"
#include <fcntl.h>

//this checks if the file passed in argv ends with .cub
//only that is checks in reverse, so it checks for buc.
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

//this ft counts how many lines there are in a file so that we can allocate the 2d array
int	how_many_lines_file(int fd)
{
	char	*gnl_line;
	int		count;

	count = 0;
	gnl_line = get_next_line(fd);
	if (!gnl_line)
		return (-1);
	while (gnl_line)
	{
		count++;
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	return (count);
}

//this ft places the file using get_next_line into the 2d arrray
char	**get_content_into_array(char **array, int fd, int count)
{
	int index;

	index = 0;
	while (index < count)
	{
		array[index] = get_next_line(fd);
		if (!array[index])
			break ;
		index++;
	}
	return (array);
}

//this ft allocates a 2d array to store the map in
char	**get_content_file(int fd, char *argv[])
{
	char	**array;
	int		count;

	count = how_many_lines_file(fd);
	if (count == -1)
		return (NULL);
	array = ft_calloc(count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free_2d_array(array);
		return (NULL);	
	}
	array = get_content_into_array(array, fd, count);
	return (array);
}

//the main of getting the entire file into full_file
t_parser *get_info_file(t_parser *parser_s, char *argv[])
{
	int	fd;
	
	if (check_argv(argv) == -1)
		error_parser(parser_s, "Map doesn't end with .cub");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_parser(parser_s, "Failed to open the file, either open failed, the file doens't have reading rights or doesn't exist");
	parser_s->full_file = get_content_file(fd, argv);
	close(fd);
	if (!parser_s->full_file)
		error_parser(parser_s, "Failed to get the content of the file");
	return (parser_s);
}