/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:05:00 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/07 15:47:03 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_move(t_game *game)
{
	game->move = game->move + 1;
	ft_printf("Mouvement numéro : %d !\n", game->move);
}

//system("aplay sounds/victory.wav &");
void	success_game(t_game *game)
{
	count_move(game);
	ft_printf("Tu as reussi !\n");
	if (BONUS)
		system("afplay sounds/victory.wav &");
	destroy_game(game);
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
