/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:39:13 by dancel            #+#    #+#             */
/*   Updated: 2024/12/21 16:49:46 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "../lib/minilibx-linux/mlx.h"

# define FLOOR		"ressource/floor.xpm"
# define WALL		"ressource/wall.xpm"
# define CHEST		"ressource/collectible.xpm"
# define EXIT0		"ressource/exit0.xpm"
# define EXIT1		"ressource/exit1.xpm"
# define PLAYER_02	"ressource/p03.xpm"
# define PLAYER_12	"ressource/p13.xpm"
# define PLAYER_22	"ressource/p23.xpm"
# define PLAYER_32	"ressource/p33.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	void	*mlx;
	void	*win;
	t_point	size;
	t_point	pos_p;
	t_image	floor;
	t_image	wall;
	t_image	chest;
	t_image	exit0;
	t_image	exit1;
	t_image	player_02;
	t_image	player_12;
	t_image	player_22;
	t_image	player_32;
	int		dir_p;
	int		n_moves;
	int		collected;
	int		n_c;
	int		n_e;
	int		temp;
	int		fd;
}			t_game;
/*

# so_long.c
# ============================*/

void	exit_so_long(t_game *game, char *s);
void	destroy_image(t_game *game);
void	destroy_map(t_game *game);
int		main(int argc, char **argv);
/*

# open_and_parse.c
# ============================*/

void	open_n_parse_the_map(t_game *game);
int		parse_the_map(t_game *game);
int		ptm1(int j, int e, int p, t_game *game);
void	copy_the_map(t_game *game);
int		ptm2(int x, int y, t_game *game);
/*

# create_gui.c.c
# ============================*/

void	init_mlx(t_game *game);
t_image	new_image(char *path, t_game *game);
int		map_display(t_game *game);
void	map_display_2(int j, int i, t_game *game);
/*

# moves.c
# ============================*/

int		key_handler(int keycode, t_game *game);
int		close_window(t_game *game);
void	move_player(int x, int y, int dir, t_game *game);

#endif