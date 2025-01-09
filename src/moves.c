/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:47:27 by dancel            #+#    #+#             */
/*   Updated: 2024/12/21 01:46:30 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p.x;
	y = game->pos_p.y;
	if (keycode == 65307)
		exit_so_long(game, "");
	if ((keycode == 100 || keycode == 65363) && !(game->map[y][x + 1] == '1'
		|| (game->map[y][x + 1] == 'E' && game->collected != game-> n_c)))
		move_player(game->pos_p.x + 1, game->pos_p.y, 3, game);
	if ((keycode == 97 || keycode == 65361) && !(game->map[y][x - 1] == '1'
		|| (game->map[y][x - 1] == 'E' && game->collected != game-> n_c)))
		move_player(game->pos_p.x - 1, game->pos_p.y, 1, game);
	if ((keycode == 119 || keycode == 65362) && !(game->map[y - 1][x] == '1'
		|| (game->map[y - 1][x] == 'E' && game->collected != game-> n_c)))
		move_player(game->pos_p.x, game->pos_p.y - 1, 2, game);
	if ((keycode == 115 || keycode == 65364) && !(game->map[y + 1][x] == '1'
		|| (game->map[y + 1][x] == 'E' && game->collected != game-> n_c)))
		move_player(game->pos_p.x, game->pos_p.y + 1, 0, game);
	return (map_display(game));
}

int	close_window(t_game *game)
{
	exit_so_long(game, "");
	return (0);
}

void	move_player(int x, int y, int dir, t_game *game)
{
	ft_printf("Score : %d\n", ++game->n_moves);
	game->pos_p.x = x;
	game->pos_p.y = y;
	game->dir_p = dir;
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E' && game->collected == game-> n_c)
		exit_so_long(game, "Victory !\n");
}
