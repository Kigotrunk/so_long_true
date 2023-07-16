/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:23:46 by kortolan          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:50 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *s);
char	*ft_free(char *buffer, char *b);
char	*ft_end_of_line(char *buffer);
char	*ft_next_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*stc_c;
	char		*s1;

	if (BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stc_c = ft_read(fd, stc_c);
	if (!stc_c)
		return (0);
	s1 = ft_end_of_line(stc_c);
	stc_c = ft_next_line(stc_c);
	if (s1[0] == '\0')
	{
		free (s1);
		return (NULL);
	}
	return (s1);
}

char	*ft_read(int fd, char *s)
{
	char	*buffer;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			free (s);
			return (0);
		}
		buffer[i] = '\0';
		s = ft_free(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (s);
}

char	*ft_free(char *buffer, char *b)
{
	char	*temp;

	temp = ft_strjoin(buffer, b);
	free (buffer);
	return (temp);
}

char	*ft_end_of_line(char *buffer)
{
	char	*temp;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		temp[i++] = '\n';
	return (temp);
}

char	*ft_next_line(char *buffer)
{
	char	*s1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	s1 = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i])
		s1[j++] = buffer[i++];
	free (buffer);
	return (s1);
}
