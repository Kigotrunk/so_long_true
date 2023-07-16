/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:06:54 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 08:12:43 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_up(t_element *test)
{
	int	x;
	int	y;

	x = 0;
	while (test->map[x])
	{
		y = 0;
		while (test->map[x][y])
		{
			if (test->map[x][y] == 'P')
			{
				if (test->map[x - 1][y] != '1' && test->map[x - 1][y] != 'E')
				{
					test->map[x - 1][y] = 'P';
					test->map[x][y] = '0';
				}
				else if (test->map[x - 1][y] == 'E' && no_item(test))
					exit(EXIT_SUCCESS);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_moove_down(t_element *test)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (test->map[x])
	{
		y = 0;
		while (test->map[x][y])
		{
			if (test->map[x][y] == 'P')
			{
				if (test->map[x + 1][y] != '1' && test->map[x + 1][y] != 'E')
				{
					test->map[x + 1][y] = 'P';
					test->map[x][y] = '0';
					return ;
				}
				else if (test->map[x + 1][y] == 'E' && no_item(test))
					exit(EXIT_SUCCESS);
			}
			y++;
		}
		x++;
	}
}

void	ft_moove_left(t_element *test)
{
	int	x;
	int	y;

	x = 0;
	while (test->map[x])
	{
		y = 0;
		while (test->map[x][y])
		{
			if (test->map[x][y] == 'P')
			{
				if (test->map[x][y - 1] != '1' && test->map[x][y - 1] != 'E')
				{
					test->map[x][y - 1] = 'P';
					test->map[x][y] = '0';
				}
				else if (test->map[x][y - 1] == 'E' && no_item(test))
					exit(EXIT_SUCCESS);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_moove_right(t_element *test)
{
	int	x;
	int	y;

	x = 0;
	while (test->map[x])
	{
		y = 0;
		while (test->map[x][y])
		{
			if (test->map[x][y] == 'P')
			{
				if (test->map[x][y + 1] != '1' && test->map[x][y + 1] != 'E')
				{
					test->map[x][y + 1] = 'P';
					test->map[x][y] = '0';
				}
				else if (test->map[x][y + 1] == 'E' && no_item(test))
					exit(EXIT_SUCCESS);
				return ;
			}
			y++;
		}
		x++;
	}
}

int	no_item(t_element *test)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (test->map[x])
	{
		y = 0;
		while (test->map[x][y])
		{
			if (test->map[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
