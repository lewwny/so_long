/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:15:09 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/08 11:21:00 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	size = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[j + i] == needle[j]
			&& needle[j] && haystack[j + i])
		{
			j++;
			if (j == size)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("%s", ft_strnstr(argv[1], argv[2], 5));
	return (0);
}*/
