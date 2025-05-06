/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:43:08 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/04/30 14:26:41 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrui(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbrui(n / 10);
		count += ft_putnbrui(n % 10);
	}
	else
		count += ft_putchari(n + 48);
	return (count);
}
