/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:13:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/01/03 14:57:38 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	x;
	char			*dest2;
	const char		*src2;
	unsigned int	y;

	if (!dest && !src)
		return (NULL);
	dest2 = dest;
	src2 = src;
	x = 0;
	y = 0;
	while (x < n)
	{
		dest2[x] = src2[x];
		x++;
	}
	return ((void *)dest);
}

void	*ft_realloc(void *ptr, size_t m)
{
	void	*nptr;
	int		x;

	if (m)
	{
		if (!ptr)
		{
			nptr = malloc(m);
			return (nptr);
		}
		nptr = malloc(m);
		ft_memcpy(nptr, ptr, m);
		free (ptr);
		return (nptr);
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
