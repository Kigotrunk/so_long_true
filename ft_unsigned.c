/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:22:54 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 07:52:49 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_u(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
	return (i);
}

int	ft_format_u(unsigned int i)
{
	int		len;
	char	*tab;

	len = 0;
	tab = ft_utoa(i);
	len = ft_count_u(tab);
	free(tab);
	return (len);
}

static int	len(long nb)
{
	int	x;

	x = 0;
	if (nb == 0)
	{
		x = 1;
		return (x);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		x++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		x++;
	}
	return (x);
}

char	*ft_utoa(unsigned int n)
{
	char	*s;
	int		y;

	y = len(n);
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)malloc(sizeof(char) * (y + 1));
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	s[y] = '\0';
	y--;
	while (n > 0)
	{
		s[y] = '0' + (n % 10);
		y--;
		n = n / 10;
	}
	return (s);
}
