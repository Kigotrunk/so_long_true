/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:20:03 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/16 11:53:59 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			x;
	t_element	*test;

	test = malloc(sizeof(t_element));
	if (argc == 1)
		return (0);
	x = 0;
	ft_ber(argv[1]);
	fd = open(argv[1], O_RDONLY);
	test->moove = 0;
	test->map = parsing(fd);
	nb_parsing(test->map);
	test->mlx_ptr = mlx_init();
	test->mlx_win = mlx_new_window(test->mlx_ptr, len3(test->map[0]) * 64, 
			len2(test->map) * 64, "KGAME");
	ft_generate_sprite(test);
	ft_print_img(test);
	mlx_hook(test->mlx_win, 2, 0, &ft_deplacement, test);
	mlx_hook(test->mlx_win, 17, 0, ft_leave, NULL);
	mlx_loop(test->mlx_ptr);
	(void) argc;
	(void) argv;
	return (0);
}

void	ft_print_img(t_element *test)
{
	int	i;
	int	j;

	i = 0;
	while (test->map[i])
	{
		j = 0;
		while (test->map[i][j])
		{
			ft_print_img_utils(test, i, j);
			j++;
		}
		i++;
	}
}

int	ft_deplacement(int key, t_element *test)
{
	if (key == 126)
		ft_moove_up(test);
	if (key == 125)
		ft_moove_down(test);
	if (key == 123)
		ft_moove_left(test);
	if (key == 124)
		ft_moove_right(test);
	if (key == 123 || key == 124 || key == 125 
		|| key == 126)
	{
		test->moove += 1;
		ft_printf("%d\n", test->moove);
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
	mlx_clear_window(test->mlx_ptr, test->mlx_win);
	ft_print_img(test);
	return (0);
}

void	ft_generate_sprite(t_element *test)
{
	test->player_sprite.img = mlx_xpm_file_to_image(test->mlx_ptr, 
			"./sprite/player1.xpm", 
			&test->player_sprite.x, &test->player_sprite.y);
	test->wall_sprite.img = mlx_xpm_file_to_image(test->mlx_ptr, 
			"./sprite/wall.xpm", 
			&test->wall_sprite.x, &test->wall_sprite.y);
	test->exit_sprite.img = mlx_xpm_file_to_image(test->mlx_ptr, 
			"./sprite/exit.xpm", 
			&test->exit_sprite.x, &test->exit_sprite.y);
	test->floor_sprite.img = mlx_xpm_file_to_image(test->mlx_ptr, 
			"./sprite/floor.xpm", 
			&test->floor_sprite.x, &test->floor_sprite.y);
	test->item_sprite.img = mlx_xpm_file_to_image(test->mlx_ptr, 
			"./sprite/item.xpm", 
			&test->item_sprite.x, &test->item_sprite.y);
}

int	ft_leave(void)
{
	exit(EXIT_SUCCESS);
}
