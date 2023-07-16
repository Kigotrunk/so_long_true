/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_.c                         	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:41:26 by kortolan          #+#    #+#             */
/*   Updated: 2023/01/13 10:53:41 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *dest, int d, size_t n)
{
	unsigned char	*ptr;

	ptr = dest;
	while (n-- > 0)
		*ptr++ = d;
	return (dest);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int		z;
	char	*s3;

	x = ft_strlen((char *)s1);
	y = ft_strlen((char *)s2);
	if (!s1 && !s2)
		return (0);
	s3 = (char *)malloc((x + y + 1) * sizeof(char));
	if (!s3)
		return (0);
	z = -1;
	while (s1[++z])
		s3[z] = s1[z];
	z = -1;
	while (s2[++z])
	{
		s3[x] = s2[z];
		x++;
	}
	s3[x] = '\0';
	return (s3);
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	if (!str)
	{
		write(1, "ERROR ! empty map\n", 19);
		exit(EXIT_FAILURE);
	}
	while (str[a])
		a++;
	return (a);
}

char	*ft_strchr(const char *src, int c)
{
	int		x;
	char	cc;

	cc = (char)c;
	x = 0;
	while (src[x])
	{
		if (src[x] == cc)
			return ((char *)&src[x]);
		x++;
	}
	if (src[x] == cc)
		return ((char *)&src[x]);
	return (0);
}
