/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:05:00 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 18:05:49 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_move(void)
{
	static int	count = 0;

	count++;
	ft_printf("Mouvement numéro : %d !\n", count);
}

void	success_game(t_game *game)
{
	free_map(game->map);
	count_move();
	ft_printf("Tu as reussi !\n");
	exit(0);
}

void	change_exit(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				map[y][x] = 'e';
			x++;
		}
		y++;
	}
}
