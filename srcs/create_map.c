/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:37:39 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 17:57:42 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *game)
{
	int	u;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/tile-wall.xpm", &u, &u);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./img/sprite-player.xpm", &u, &u);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./img/tile-floor.xpm", &u, &u);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./img/1.xpm", &u, &u);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/chest1.xpm", &u, &u);
	game->img_exit2 = mlx_xpm_file_to_image(game->mlx,
			"./img/chest2.xpm", &u, &u);
	if (!game->img_wall || !game->img_player || !game->img_floor
		|| !game->img_collectible || !game->img_exit || !game->img_exit2)
	{
		ft_printf("Error\nUne image n'a pas chargée\n");
		free_map(game->map);
		exit(1);
	}
}

static void	collectible_player(t_game *game, int *x, int *y)
{
	if (game->map[*y][*x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_player, *x * TILE_SIZE, *y * TILE_SIZE);
	else if (game->map[*y][*x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_collectible,
			*x * TILE_SIZE, *y * TILE_SIZE);
	else if (game->map[*y][*x] == 'e')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_exit2, *x * TILE_SIZE, *y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x + 1])
		{
			mlx_put_image_to_window(game->mlx,
				game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			else
				collectible_player(game, &x, &y);
			x++;
		}
		y ++;
	}
}
