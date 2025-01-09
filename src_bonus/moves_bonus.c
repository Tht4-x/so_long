/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:47:27 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 23:00:09 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_handler(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p.x;
	y = game->pos_p.y;
	if (keycode == 65307 || keycode == 17)
		exit_so_long(game, "");
	if ((keycode == 100 || keycode == 65363) && game->map[y][x + 1] != 'A'
		&& !(game->map[y][x + 1] == 'E' && game->collected != game-> n_c))
		move_player(game->pos_p.x + 1, game->pos_p.y, 3, game);
	if ((keycode == 97 || keycode == 65361) && game->map[y][x - 1] != 'A'
		&& !(game->map[y][x - 1] == 'E' && game->collected != game-> n_c))
		move_player(game->pos_p.x - 1, game->pos_p.y, 1, game);
	if ((keycode == 119 || keycode == 65362) && game->map[y - 1][x] != 'A'
		&& !(game->map[y - 1][x] == 'E' && game->collected != game-> n_c))
		move_player(game->pos_p.x, game->pos_p.y - 1, 2, game);
	if ((keycode == 115 || keycode == 65364) && game->map[y + 1][x] != 'A'
		&& !(game->map[y + 1][x] == 'E' && game->collected != game-> n_c))
		move_player(game->pos_p.x, game->pos_p.y + 1, 0, game);
	return (map_display(game));
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
		exit_so_long(game, "1");
	else if (game->map[y][x] == '1')
		exit_so_long(game, "0You can't swim !");
	else if ((x == game->t_1.x && y == game->t_1.y)
		|| (x == game->t_2.x && y == game->t_2.y)
		|| (x == game->t_3.x && y == game->t_3.y))
		exit_so_long(game, "0You can't eat turtle's shell !");
}

int	animation(t_game *game)
{
	clock_t	current_time;

	current_time = clock();
	if (current_time - game->last_time > 10000)
	{
		game->last_time = current_time;
		game->frame = ++game->frame % 3;
	}
	if (!game->frame % 3)
	{
		game->t_1 = move_the_turtles(game->t_1, game);
		game->t_2 = move_the_turtles(game->t_2, game);
		game->t_3 = move_the_turtles(game->t_3, game);
	}
	if (time(NULL) > game->game_time + TIME_OUT)
		exit_so_long(game, "0TIME OUT !");
	usleep(100000);
	map_display(game);
	return (0);
}

void	handle_turtle(int x, int y, t_game *game)
{
	if (!game->t_1.x)
		game->t_1 = (t_turtle){x, y, 0};
	else if (game->t_1.x && !game->t_2.x)
		game->t_2 = (t_turtle){x, y, 1};
	else if (game->t_2.x && !game->t_3.x)
		game->t_3 = (t_turtle){x, y, 2};
	else if (game->t_3.x)
		exit_so_long(game, "Error :\nToo many turtles !");
}

t_turtle	move_the_turtles(t_turtle t_n, t_game *game)
{
	int	dir;

	dir = rand() % 4;
	if (t_n.x && dir == 0 && game->map[t_n.y + 1][t_n.x] == '0')
		++t_n.y;
	else if (t_n.x && dir == 1 && game->map[t_n.y][t_n.x - 1] == '0')
		--t_n.x;
	else if (t_n.x && dir == 2 && game->map[t_n.y - 1][t_n.x] == '0')
		--t_n.y;
	else if (t_n.x && dir == 3 && game->map[t_n.y][t_n.x + 1] == '0')
		++t_n.x;
	t_n.dir = dir;
	if (t_n.x == game->pos_p.x && t_n.y == game->pos_p.y)
		exit_so_long(game, "0You can't eat turtle's shell !");
	return (t_n);
}
