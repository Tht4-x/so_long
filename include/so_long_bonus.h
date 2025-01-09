/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:40:42 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 22:54:41 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <time.h>
# include "libft.h"
# include "ft_printf.h"
# include "../lib/minilibx-linux/mlx.h"

# ifndef TIME_OUT
#  define TIME_OUT 30
# endif

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_turtle
{
	int	x;
	int	y;
	int	dir;
}			t_turtle;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	void		*mlx;
	void		*win;
	time_t		game_time;
	float		last_time;
	int			frame;
	t_point		size;
	t_point		pos_p;
	t_image		so_long;
	t_image		ggez;
	t_image		lose;
	t_image		floor;
	t_image		wall;
	t_image		chest;
	t_image		exit0;
	t_image		exit1;
	t_image		palmier;
	t_image		player_00;
	t_image		player_01;
	t_image		player_02;
	t_image		player_10;
	t_image		player_11;
	t_image		player_12;
	t_image		player_20;
	t_image		player_21;
	t_image		player_22;
	t_image		player_30;
	t_image		player_31;
	t_image		player_32;
	int			dir_p;
	t_image		turtle_0;
	t_image		turtle_1;
	t_image		turtle_2;
	t_image		turtle_3;
	t_turtle	t_1;
	t_turtle	t_2;
	t_turtle	t_3;
	int			n_moves;
	int			collected;
	int			n_c;
	int			n_e;
	int			temp;
	int			fd;
}			t_game;
/*

# so_long_bonus.c
# ============================*/

int			close_window(t_game *game);
int			main(int argc, char **argv);
/*

# open_and_parse_bonus.c
# ============================*/

void		open_n_parse_the_map(t_game *game);
int			parse_the_map(t_game *game);
int			ptm1(int j, int e, int p, t_game *game);
void		copy_the_map(t_game *game);
int			ptm2(int x, int y, t_game *game);
/*

# create_gui.c_bonus.c
# ============================*/

void		init_mlx(t_game *game);
void		load_image(t_game *game);
t_image		new_image(char *path, t_game *game);
int			map_display(t_game *game);
void		counter(t_game *game);
/*

# map_display.c
# ============================*/

void		map_display_1(int j, int i, t_game *game);
void		map_display_2(int j, int i, t_game *game);
void		map_display_3(int j, int i, t_game *game);
void		map_display_4(int j, int i, t_game *game);
void		map_display_5(int j, int i, t_game *game);
/*

# moves_bonus.c
# ============================*/

int			key_handler(int keycode, t_game *game);
void		move_player(int x, int y, int dir, t_game *game);
int			animation(t_game *game);
void		handle_turtle(int i, int j, t_game *game);
t_turtle	move_the_turtles(t_turtle t_n, t_game *game);
/*

# exit_so_long.c
# ============================*/

void		exit_so_long(t_game *game, char *s);
void		destroy_image(t_game *game);
void		destroy_map(t_game *game);
void		ending_screen_1(char *s, t_game *game);
void		ending_screen_2(char *s, t_game *game);

#endif