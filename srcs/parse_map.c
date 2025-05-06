/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:36:45 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 10:52:58 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_collectible(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map [y][x++] == 'C')
				count++;
		}
		y++;
	}
	if (count > 0)
		return (1);
	return (0);
}

static int	check_exit(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map [y][x++] == 'E')
				count++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static int	check_player(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map [y][x++] == 'P')
				count++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void	parse_map(char **map)
{
	if (!check_collectible(map))
		invalid_map(map);
	if (!check_exit(map))
		invalid_map(map);
	if (!check_player(map))
		invalid_map(map);
}
