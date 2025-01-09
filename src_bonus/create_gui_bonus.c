/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gui_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:36:23 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 22:55:56 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_so_long(game, "Error :\nmlx pointer not found");
	game->win = mlx_new_window(game->mlx, \
		(game->size.x + 1) * 128, (game->size.y + 1) * 128, "So long");
	if (!game->win)
		exit_so_long(game, "Error :\nwindows pointer not found");
	game->so_long = new_image("ressource/so_long.xpm", game);
	mlx_put_image_to_window(game->mlx, game->win, game->so_long.xpm_ptr, \
		(game->size.x + 1) * 64 - 192, (game->size.y + 1) * 64 - 192);
	sleep(2);
	mlx_destroy_image(game->mlx, game->so_long.xpm_ptr);
	load_image(game);
	map_display(game);
}

void	load_image(t_game *game)
{
	game->palmier = new_image("ressource/palmier.xpm", game);
	game->floor = new_image("ressource/floor.xpm", game);
	game->wall = new_image("ressource/wall.xpm", game);
	game->chest = new_image("ressource/collectible.xpm", game);
	game->exit0 = new_image("ressource/exit0.xpm", game);
	game->exit1 = new_image("ressource/exit1.xpm", game);
	game->player_00 = new_image("ressource/p01.xpm", game);
	game->player_01 = new_image("ressource/p02.xpm", game);
	game->player_02 = new_image("ressource/p03.xpm", game);
	game->player_10 = new_image("ressource/p11.xpm", game);
	game->player_11 = new_image("ressource/p12.xpm", game);
	game->player_12 = new_image("ressource/p13.xpm", game);
	game->player_20 = new_image("ressource/p21.xpm", game);
	game->player_21 = new_image("ressource/p22.xpm", game);
	game->player_22 = new_image("ressource/p23.xpm", game);
	game->player_30 = new_image("ressource/p31.xpm", game);
	game->player_31 = new_image("ressource/p32.xpm", game);
	game->player_32 = new_image("ressource/p33.xpm", game);
	game->turtle_0 = new_image("ressource/turtle0.xpm", game);
	game->turtle_1 = new_image("ressource/turtle1.xpm", game);
	game->turtle_2 = new_image("ressource/turtle2.xpm", game);
	game->turtle_3 = new_image("ressource/turtle3.xpm", game);
	game->ggez = new_image("ressource/victory.xpm", game);
	game->lose = new_image("ressource/game_over.xpm", game);
}

t_image	new_image(char *path, t_game *game)
{
	t_image	image;

	image.xpm_ptr = mlx_xpm_file_to_image(game->mlx, path, &image.x, &image.y);
	if (!image.xpm_ptr)
		exit_so_long(game, "Error :\nimage not found");
	return (image);
}

int	map_display(t_game *game)
{
	int		i;
	int		j;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			map_display_1(j, i, game);
			map_display_2(j, i, game);
			map_display_3(j, i, game);
			if (i > 0 && j > 0)
			{
				map_display_4(j, i, game);
				map_display_5(j, i, game);
			}
		}
	}
	counter(game);
	return (0);
}

void	counter(t_game *game)
{
	char	*temp;

	temp = ft_itoa(game->n_moves);
	mlx_string_put(game->mlx, game->win, 20, 20, 0xFF0000, "SCORE:");
	mlx_string_put(game->mlx, game->win, 70, 20, 0x000000, temp);
	free(temp);
	temp = ft_itoa(-(time(NULL) - game->game_time - TIME_OUT));
	mlx_string_put(game->mlx, game->win, 100, 20, 0xFF0000, "TIME OUT:");
	mlx_string_put(game->mlx, game->win, 160, 20, 0x000000, temp);
	free(temp);
}
