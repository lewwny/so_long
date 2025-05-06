/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:57:05 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 19:14:04 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_mlx(t_game *game)
{
	free_map(game->map);
	ft_printf("Error\nMLX failed\n");
	exit(1);
}

void	error_load(t_game *game)
{
	ft_printf("Error\nImage load fail\n");
	free_map(game->map);
	if (game->img_collectible)
		free(game->img_collectible);
	exit(1);
}

void	malloc_error2(t_game *game)
{
	ft_printf("Error\nProblème d'allocation mémoire\n");
	free_map(game->map);
	if (game->img_collectible)
		free(game->img_collectible);
	exit(1);
}
