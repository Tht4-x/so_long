/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:32:16 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 22:32:57 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_display_1(int j, int i, t_game *game)
{
	if (game->map[j][i] == '0' || game->map[j][i] == 'P'
		|| game->map[j][i] == 'T')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->floor.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->wall.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chest.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == 'E' && game->collected != game->n_c)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->exit0.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == 'E' && game->collected == game->n_c)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->exit1.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == 'A')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->palmier.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 0 && game->frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_00.xpm_ptr, 128 * i, 128 * j);
}

void	map_display_2(int j, int i, t_game *game)
{
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 0 && game->frame == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_01.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 0 && game->frame == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_02.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 1 && game->frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_10.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 1 && game->frame == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_11.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 1 && game->frame == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_12.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 2 && game->frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_20.xpm_ptr, 128 * i, 128 * j);
}

void	map_display_3(int j, int i, t_game *game)
{
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 2 && game->frame == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_21.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 2 && game->frame == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_22.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 3 && game->frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_30.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 3 && game->frame == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_31.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j \
		&& game->dir_p == 3 && game->frame == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_32.xpm_ptr, 128 * i, 128 * j);
}

void	map_display_4(int j, int i, t_game *game)
{
	if (game->t_1.x == i && game->t_1.y == j \
		&& game->t_1.dir == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_0.xpm_ptr, 128 * i, 128 * j);
	if (game->t_1.x == i && game->t_1.y == j \
		&& game->t_1.dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_1.xpm_ptr, 128 * i, 128 * j);
	if (game->t_1.x == i && game->t_1.y == j \
		&& game->t_1.dir == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_2.xpm_ptr, 128 * i, 128 * j);
	if (game->t_1.x == i && game->t_1.y == j \
		&& game->t_1.dir == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_3.xpm_ptr, 128 * i, 128 * j);
	if (game->t_2.x == i && game->t_2.y == j \
		&& game->t_2.dir == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_0.xpm_ptr, 128 * i, 128 * j);
	if (game->t_2.x == i && game->t_2.y == j \
		&& game->t_2.dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_1.xpm_ptr, 128 * i, 128 * j);
}

void	map_display_5(int j, int i, t_game *game)
{
	if (game->t_2.x == i && game->t_2.y == j \
		&& game->t_2.dir == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_2.xpm_ptr, 128 * i, 128 * j);
	if (game->t_2.x == i && game->t_2.y == j \
		&& game->t_2.dir == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_3.xpm_ptr, 128 * i, 128 * j);
	if (game->t_3.x == i && game->t_3.y == j \
		&& game->t_3.dir == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_0.xpm_ptr, 128 * i, 128 * j);
	if (game->t_3.x == i && game->t_3.y == j \
		&& game->t_3.dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_1.xpm_ptr, 128 * i, 128 * j);
	if (game->t_3.x == i && game->t_3.y == j \
		&& game->t_3.dir == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_2.xpm_ptr, 128 * i, 128 * j);
	if (game->t_3.x == i && game->t_3.y == j \
		&& game->t_3.dir == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->turtle_3.xpm_ptr, 128 * i, 128 * j);
}
