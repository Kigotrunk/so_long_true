/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:58:51 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 12:57:44 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len3(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	len2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_print_img_utils(t_element *test, int i, int j)
{
	if (test->map[i][j] == '1')
		mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
			test->wall_sprite.img, j * 64, i * 64);
	else if (test->map[i][j] == '0')
		mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
			test->floor_sprite.img, j * 64, i * 64);
	else if (test->map[i][j] == 'P')
		mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
			test->player_sprite.img, j * 64, i * 64);
	else if (test->map[i][j] == 'C')
		mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
			test->item_sprite.img, j * 64, i * 64);
	else if (test->map[i][j] == 'E')
		mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
			test->exit_sprite.img, j * 64, i * 64);
}

void	ft_ber(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 4;
	while (str[i])
		i++;
	if (i < 3)
	{
		ft_printf("%s\n", "ERROR ! map need to be .ber");
		exit(EXIT_FAILURE);
	}
	i--;
	if (str[i] != 'r' && str[i - 1] != 'e' 
		&& str[i - 2] != 'b' && str[i - 3] != '.')
	{
		ft_printf("%s\n", "ERROR ! map need to be .ber");
		exit(EXIT_FAILURE);
	}
	if (open(str, O_RDONLY) == -1)
	{
		ft_printf("ERROR ! FILE DOSENT EXIST\n");
		exit(EXIT_FAILURE);
	}
}

void	player(char **map)
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
			if (map[i][j] == 'P')
				x++;
			j++;
		}
		i++;
	}
	if (x > 1)
	{
		ft_printf("ERROR ! more than 1 player\n");
		exit(EXIT_FAILURE);
	}
	return ;
}
