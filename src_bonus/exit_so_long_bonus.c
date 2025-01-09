/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_so_long_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:39:54 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 23:11:09 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_so_long(t_game *game, char *s)
{
	if (s[0] == '1' || s[0] == '0')
		ending_screen_1(s, game);
	else
		write(2, s, ft_strlen(s));
	if (game)
	{
		destroy_map(game);
		if (game->floor.xpm_ptr)
			destroy_image(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		close(game->fd);
		free(game);
	}
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
	mlx_destroy_image(game->mlx, game->palmier.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->chest.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit0.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit1.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_00.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_01.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_02.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_10.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_11.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_12.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_20.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_21.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_22.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_30.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_31.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_32.xpm_ptr);
	mlx_destroy_image(game->mlx, game->turtle_0.xpm_ptr);
	mlx_destroy_image(game->mlx, game->turtle_1.xpm_ptr);
	mlx_destroy_image(game->mlx, game->turtle_2.xpm_ptr);
	mlx_destroy_image(game->mlx, game->turtle_3.xpm_ptr);
	mlx_destroy_image(game->mlx, game->ggez.xpm_ptr);
	mlx_destroy_image(game->mlx, game->lose.xpm_ptr);
}

void	ending_screen_1(char *s, t_game *game)
{
	time_t	t;

	t = time(NULL);
	if (s[0] == '1')
	{
		ft_printf("\033[1;32m########### VICTORY ###########\033[0m\n\n");
		ft_printf("\033[1;33m\tYou Won the Game!	   \033[0m\n\n");
		ft_printf("\033[1;32m\tCongratulations!		   \033[0m\n\n");
		ft_printf("\033[1;37m\tYour final score: %d\033[0m\n\n", game->n_moves);
		ft_printf("\033[1;32m########### VICTORY ###########\033[0m\n");
		while (1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->ggez.xpm_ptr, \
				(game->size.x + 1) * 64 - 192, (game->size.y + 1) * 64 - 192);
			if (time(NULL) - t > 2)
				break ;
		}
	}
	ending_screen_2(s, game);
}

void	ending_screen_2(char *s, t_game *game)
{
	time_t	t;

	t = time(NULL);
	if (s[0] == '0')
	{
		ft_printf("\033[1;31m########## GAME OVER ##########\033[0m\n\n");
		ft_printf("\033[1;37m\tYou lose the Game	   \033[0m\n\n");
		ft_printf("\033[1;31m\t%s		   \033[0m\n\n", s + 1);
		ft_printf("\033[1;37m\tYour final score: %d\033[0m\n\n", game->n_moves);
		ft_printf("\033[1;31m########## GAME OVER ##########\033[0m\n");
		while (1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->lose.xpm_ptr, \
				(game->size.x + 1) * 64 - 192, (game->size.y + 1) * 64 - 192);
			if (time(NULL) - t > 2)
				break ;
		}
	}
}
