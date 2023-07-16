/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:51 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 08:09:31 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_format_s(const char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (ft_format_s("(null)"));
	while (string[i])
		i += ft_putchar(string[i]);
	return (i);
}

int	ft_count_i(char *tab)
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

int	ft_format_i(int i)
{
	int		len;
	char	*tab;

	len = 0;
	tab = ft_itoa(i);
	len = ft_count_i(tab);
	free(tab);
	return (len);
}
