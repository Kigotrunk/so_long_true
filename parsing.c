/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:50:34 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 12:53:34 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parsing(int fd)
{
	char	**map;
	char	*temp;
	char	*tempgnl;

	temp = ft_strdup("");
	tempgnl = ft_strjoin(temp, get_next_line(fd));
	if (!temp)
		return (0);
	while (tempgnl)
	{
		temp = ft_strjoin(temp, tempgnl);
		tempgnl = get_next_line(fd);
	}
	free(tempgnl);
	map = ft_split(temp, '\n');
	free(temp);
	test(map);
	road(map);
	player(map);
	return (map);
}

int	rectangle(char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 1;
	y = 0;
	while (map[0][i])
		i++;
	while (map[x])
	{
		while (map[x][y])
		{
			y++;
		}
		if (y != i)
			return (-1);
		x++;
		y = 0;
	}
	return (0);
}

int	ft_count_line(char *file)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!file)
		return (0);
	while (!file[i])
	{
		if (file[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

void	road(char **map)
{
	int		count;
	char	**cpy_map;

	count = count_c_e(map);
	cpy_map = cp_map(map);
	find_path(cpy_map, pos_player_x(map), pos_player_y(map), &count);
	if (count != 0)
	{
		ft_printf("ERROR ! BAD PATH\n");
		exit(EXIT_FAILURE);
	}
}

char	**cp_map(char **map)
{
	char	**cpy_map;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (map[i])
		i++;
	cpy_map = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}
