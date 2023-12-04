/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:02:01 by dhussain          #+#    #+#             */
/*   Updated: 2023/12/04 10:35:35 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	a;
	size_t	b;

	h = (char *)haystack;
	n = (char *)needle;
	a = 0;
	if (n[0] == '\0')
		return (h);
	while (h[a] != '\0')
	{
		b = 0;
		while (h[a + b] == n[b] && (a + b) < len)
		{
			if (n[b] == '\0' && h[a + b] == '\0')
				return (&h[a]);
		b++;
		}
		if (n[b] == '\0')
			return (h + a);
		a++;
	}
	return (0);
}