/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:57:22 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 10:31:15 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**read_file_to_map(int fd)
{
	char	**map;
	char	*line;
	int		count;
	int		i;
	char	**tmp;

	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp = malloc(sizeof(char *) * (count + 2));
		if (!tmp)
			malloc_error();
		i = 0;
		while (i < count)
		{
			tmp[i] = map[i];
			i++;
		}
		tmp[count] = line;
		tmp[count + 1] = NULL;
		if (map)
			free(map);
		map = tmp;
		count++;
		line = get_next_line(fd);
	}
	return (map);
}

char	**read_file(char *file)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		wrong_file();
	map = read_file_to_map(fd);
	close(fd);
	return (map);
}
