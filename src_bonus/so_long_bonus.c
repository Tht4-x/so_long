/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:00:33 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 23:17:04 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	exit_so_long(game, "");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_so_long(game, "Error :\nmalloc failed");
	if (argc != 2)
		exit_so_long(game, "Error :\nusage : <map.ber>");
	if ((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 10)))
		exit_so_long(game, "Error :\nwrong extension");
	*game = (t_game){0};
	game->fd = open(argv[1], O_RDONLY);
	open_n_parse_the_map(game);
	game->game_time = time(NULL);
	init_mlx(game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	game->last_time = clock();
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
	return (0);
}
