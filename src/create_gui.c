/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:53:44 by dancel            #+#    #+#             */
/*   Updated: 2024/12/21 16:43:03 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_so_long(game, "Error :\nmlx pointer not found");
	game->win = mlx_new_window(game->mlx, \
		(game->size.x + 1) * 128, (game->size.y + 1) * 128, "So long");
	if (!game->win)
		exit_so_long(game, "Error :\nwindows pointer not found");
	game->floor = new_image(FLOOR, game);
	game->wall = new_image(WALL, game);
	game->chest = new_image(CHEST, game);
	game->exit0 = new_image(EXIT0, game);
	game->exit1 = new_image(EXIT1, game);
	game->player_02 = new_image(PLAYER_02, game);
	game->player_12 = new_image(PLAYER_12, game);
	game->player_22 = new_image(PLAYER_22, game);
	game->player_32 = new_image(PLAYER_32, game);
	map_display(game);
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
	char	*temp;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			if (game->map[j][i] == 'E' && game->collected != game->n_c)
				mlx_put_image_to_window(game->mlx, game->win, \
					game->exit0.xpm_ptr, 128 * i, 128 * j);
			if (game->map[j][i] == 'E' && game->collected == game->n_c)
				mlx_put_image_to_window(game->mlx, game->win, \
					game->exit1.xpm_ptr, 128 * i, 128 * j);
			map_display_2(j, i, game);
		}
	}
	temp = ft_itoa(game->n_moves);
	mlx_string_put(game->mlx, game->win, 20, 20, 0xFF0000, "SCORE :");
	mlx_string_put(game->mlx, game->win, 70, 20, 0x000000, temp);
	free(temp);
	return (0);
}

void	map_display_2(int j, int i, t_game *game)
{
	if (game->map[j][i] == '0' || game->map[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->floor.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->wall.xpm_ptr, 128 * i, 128 * j);
	if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chest.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j && game->dir_p == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_02.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j && game->dir_p == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_12.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j && game->dir_p == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_22.xpm_ptr, 128 * i, 128 * j);
	if (game->pos_p.x == i && game->pos_p.y == j && game->dir_p == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player_32.xpm_ptr, 128 * i, 128 * j);
}
