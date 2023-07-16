# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 12:03:07 by kortolan          #+#    #+#              #
#    Updated: 2023/07/16 11:54:58 by kortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         =     gcc

CFLAGS     =     -Wall -Wextra -Werror -Imlx -g

LIBFT    =    libft/libft.a

SRCS     =  so_long.c \
						parsing.c \
						parsing_2.c \
						parsing_3.c \
						parsing_4.c \
						get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c \
						moove.c \
						utils.c \
						ft_format_p.c \
						ft_format.c \
						ft_hex.c \
						ft_printf.c \
						ft_unsigned.c \
						utils2.c \

OBJS    = $(SRCS:.c=.o)
            
NAME = so_long

all:    $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all
