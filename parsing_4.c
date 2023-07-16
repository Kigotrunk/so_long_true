/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:52:08 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 12:52:34 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c_e(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	find_path(char **cpy, int x, int y, int *count)
{
	if (x < 0 || y < 0)
		return ;
	if (cpy[x][y] == 'C')
		*count -= 1;
	cpy[x][y] = 'X';
	if (cpy[x][y + 1] != '1' && cpy[x][y + 1] != 'X'
		&& cpy[x][y + 1] != 'E')
		find_path(cpy, x, y + 1, count);
	if ((y - 1) >= 0 && cpy[x][y - 1] != '1' && cpy[x][y - 1] != 'X'
		&& cpy[x][y - 1] != 'E')
		find_path(cpy, x, y - 1, count);
	if (cpy[x + 1][y] != '1' && cpy[x + 1][y] != 'X'
		&& cpy[x + 1][y] != 'E')
		find_path(cpy, x + 1, y, count);
	if ((x - 1) >= 0 && cpy[x - 1][y] != '1' && cpy[x - 1][y] != 'X'
		&& cpy[x - 1][y] != 'E')
		find_path(cpy, x - 1, y, count);
}
