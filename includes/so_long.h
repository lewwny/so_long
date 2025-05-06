/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:15:31 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/06 10:48:29 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx/mlx.h"

void	arg_error(int argc, char *file);
void	wrong_file(void);
void	malloc_error(void);
void	free_map(char **map);
void	parse_map(char **map);
void	invalid_map(char **map);

char	**read_file(char *file);

#endif
