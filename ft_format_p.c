/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:54:32 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 07:51:55 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(unsigned long long i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		len++;
		i = i / 16;
	}
	return (len);
}

void	ft_ptr(unsigned long long i)
{
	if (i >= 16)
	{
		ft_ptr(i / 16);
		ft_ptr(i % 16);
	}
	else
	{
		if (i <= 9)
			ft_putchar_fd((i + '0'), 1);
		else
			ft_putchar_fd((i - 10 + 'a'), 1);
	}
}

int	ft_format_p_test(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_ptr(ptr);
		print_length += ft_len(ptr);
	}
	return (print_length);
}
