/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:14:30 by dhussain          #+#    #+#             */
/*   Updated: 2024/03/05 17:14:31 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "stdio.h"

int	ammount_input_rgb(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] == ',')
		{
			count++;
			if (line[index + 1] == '\0' || line[index + 1] == '\n')
				return (-1);
		}
		index++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

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
