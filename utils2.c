/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:46:20 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 13:04:54 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leave(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				x++;
			j++;
		}
		i++;
	}
	if (x > 1 || x == 0)
	{
		ft_printf("ERROR ! exit problem\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	nb_item(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				x++;
			j++;
		}
		i++;
	}
	if (x < 1)
	{
		ft_printf("ERROR ! no item\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	nb_parsing(char **map)
{
	leave(map);
	player(map);
	nb_item(map);
	valid_char(map);
	return ;
}

void	valid_char(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'P')
			{
				ft_printf("ERROR ! INVALID CHARACTER\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	exit_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j - 1] == 'X' || map[i][j + 1] == 'X'
						|| map[i + 1][j] == 'X' || map[i - 1][j] == 'X')
					return (1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
