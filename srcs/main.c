/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:32:27 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 10:47:00 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/so_long.h>

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
}

int	main(int argc, char **argv)
{
	char	**map;

	arg_error(argc, argv[1]);
	map = read_file(argv[1]);
	parse_map(map);
	print_map(map);
	free_map(map);
	return (0);
}
