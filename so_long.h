/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:47:26 by marvin            #+#    #+#             */
/*   Updated: 2023/07/16 12:56:35 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include "so_long.h"

typedef struct s_sprite {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_element
{
	t_sprite	player_sprite;
	t_sprite	wall_sprite;
	t_sprite	exit_sprite;
	t_sprite	floor_sprite;
	t_sprite	item_sprite;
	void		*mlx_ptr;
	void		*mlx_win;
	int			*height;
	int			*width;
	char		**map;
	int			moove;
}	t_element; 

int			ft_printf(const char *ptr, ...);
int			ft_putchar(char c);
int			ft_format_s(const char *string);
int			ft_format_i(int i);
void		ft_puthexa(unsigned long long nb, int m);
int			ft_format_hexa(unsigned long long nb, int m);
int			ft_format_p_test(unsigned long long ptr);
void		ft_ptr(unsigned long long i);
int			ft_len(unsigned long long i);
int			ft_count_u(char *tab);
int			ft_format_u(unsigned int i);
char		*ft_utoa(unsigned int n);
int			pos_player_x(char **map);
int			pos_player_y(char **map);
void		find_path(char **cpy, int x, int y, int *count);
char		**parsing(int fd);
char		**cp_map(char **map);
void		road(char **map);
int			ft_count_line(char *file);
int			count_c_e(char **map);
void		test(char **map);
int			rectangle(char **map);
int			item(char **map);
int			wall(char **map);
int			count_line(char **map);
int			player_blocked(int x, int y, char **map);
int			pos_player_x(char **map); 
int			pos_player_y(char **map);

void		ft_generate_sprite(t_element *test);
void		ft_print_img(t_element *test);
int			ft_deplacement(int key, t_element *test);
void		ft_moove_up(t_element *test);
void		ft_moove_down(t_element *test);
void		ft_moove_left(t_element *test);
void		ft_moove_right(t_element *test);
int			len3(char *map);
int			len2(char **map);
int			no_item(t_element *test);
int			ft_leave(void);
void		ft_ber(char *str);
void		ft_print_img_utils(t_element *test, int i, int j);
void		nb_item(char **map);
void		leave(char **map);
void		player(char **map);
void		nb_parsing(char **map);
void		valid_char(char **map);
int			exit_reachable(char **map);

#endif
