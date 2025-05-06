/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:32:27 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 17:50:35 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/so_long.h>

int	close_game(t_game *game)
{
	free_map(game->map);
	exit(0);
}

static void	init_game(t_game *game)
{
	int	x_size;
	int	y_size;

	y_size = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_mlx(game);
	x_size = ft_strlen(game->map[0]) - 1;
	while (game->map[y_size])
		y_size++;
	game->win = mlx_new_window(game->mlx, x_size * TILE_SIZE,
			y_size * TILE_SIZE, "so_long");
	if (!game->win)
		error_mlx(game);
	load_images(game);
	render_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	arg_error(argc, argv[1]);
	game.map = read_file(argv[1]);
	parse_map(&game);
	init_game(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	mlx_hook(game.win, 17, 0, close_game, &game);
	free_map(game.map);
	return (0);
}
