/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:45:27 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 07:52:46 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printf_int(va_list args, const char ptr);

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			len += ft_printf_int(args, ptr[i + 1]);
			i++;
		}
		else if (ptr[i] != '%')
			len += ft_putchar(ptr[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_printf_int(va_list args, const char ptr)
{
	int	len;

	len = 0;
	if (ptr == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (ptr == 'p')
		len += ft_format_p_test(va_arg(args, unsigned long long));
	else if (ptr == 's')
		len += ft_format_s(va_arg(args, const char *));
	else if (ptr == 'i' || ptr == 'd')
		len += ft_format_i(va_arg(args, int));
	else if (ptr == 'u')
		len += ft_format_u(va_arg(args, unsigned int));
	else if (ptr == 'x')
		len += ft_format_hexa(va_arg(args, unsigned long long), 0);
	else if (ptr == 'X')
		len += ft_format_hexa(va_arg(args, unsigned long long), 1);
	else if (ptr == '%')
		len += ft_putchar('%');
	return (len);
}
