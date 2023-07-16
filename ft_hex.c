/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:07:36 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 07:52:37 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puthexa(unsigned long long nb, int m)
{
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, m);
		ft_puthexa(nb % 16, m);
	}
	else if (nb <= 9)
	{
		ft_putchar_fd((nb + '0'), 1);
	}
	else if (m == 1)
		ft_putchar_fd(nb - 10 + 'A', 1);
	else if (m == 0)
		ft_putchar_fd(nb - 10 + 'a', 1);
}

int	ft_hexa_len(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_format_hexa(unsigned long long nb, int m)
{
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		ft_puthexa(nb, m);
	return (ft_hexa_len(nb));
}
