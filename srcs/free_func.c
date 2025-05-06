/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:34:08 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 19:19:29 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	destroy_game(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_exit2);
	i = 0;
	while (i < game->num_collectible_frame)
	{
		mlx_destroy_image(game->mlx, game->img_collectible[i]);
		i++;
	}
	free(game->img_collectible);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	exit(0);
}
