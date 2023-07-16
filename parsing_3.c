/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:25:13 by marvin            #+#    #+#             */
/*   Updated: 2023/07/16 08:30:51 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test(char **map)
{
	if (rectangle(map) == -1)
	{
		ft_printf("%s\n", "ERROR ! rectangle");
		exit(1);
	}
	if (wall(map) == -1)
	{
		ft_printf("%s\n", "ERROR ! need to be border by wall");
		exit(1);
	}
	if (item(map) == 0)
	{
		ft_printf("%s\n", "ERROR ! need to have min 1 item");
		exit(1);
	}
}

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
	{
		i++;
	}
	return (i);
}

int	wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0 || !map[i + 1])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	item(char **map)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				i++;
			y++;
		}
		x++;
	}
	if (i > 0)
		return (1);
	return (-1);
}
