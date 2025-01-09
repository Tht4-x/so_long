/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:38:53 by dancel            #+#    #+#             */
/*   Updated: 2024/12/24 18:30:42 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_so_long(t_game *game, char *s)
{
	if (game)
	{
		destroy_map(game);
		if (game->floor.xpm_ptr)
			destroy_image(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		close(game->fd);
		free(game);
	}
	if (s)
		write(2, s, ft_strlen(s));
	exit(1);
}

void	destroy_map(t_game	*game)
{
	int	i;

	i = -1;
	while (game->map && game->map[++i])
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (game->map_copy && game->map_copy[++i])
		free(game->map_copy[i]);
	free(game->map_copy);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->chest.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit0.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit1.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_02.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_12.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_22.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_32.xpm_ptr);
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
	init_mlx(game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
