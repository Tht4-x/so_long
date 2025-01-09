/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_parse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:29:24 by dancel            #+#    #+#             */
/*   Updated: 2024/12/23 19:10:21 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_n_parse_the_map(t_game *game)
{
	char	*s1;
	char	*s2;
	char	*s3;

	if (game->fd == -1)
		exit_so_long(game, "Error :\nmap unfind");
	s1 = get_next_line(game->fd);
	if (!s1)
		exit_so_long(game, "Error :\nmap unreadable");
	while (1)
	{
		s2 = get_next_line(game->fd);
		if (!s2)
			break ;
		s3 = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
		if (!s3)
			exit_so_long(game, "Error :\nmalloc failed");
		s1 = s3;
	}
	game->map = ft_split(s1, '\n');
	free(s1);
	if (!game->map || parse_the_map(game))
		exit_so_long(game, "Error :\ninvalid map");
}

int	parse_the_map(t_game *game)
{
	int		x;
	int		y;
	int		temp;

	y = -1;
	temp = INT_MAX;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (!(game->map[y][x] == '0' || game->map[y][x] == '1'
				|| game->map[y][x] == 'P' || game->map[y][x] == 'C'
					|| game->map[y][x] == 'E' || game->map[y][x] == 'T'
						|| game->map[y][x] == 'A'))
				return (1);
		}
		if ((x < 3 || x != temp) && temp != INT_MAX)
			return (1);
		temp = x;
	}
	game->size = (t_point){x - 1, y - 1};
	copy_the_map(game);
	return (ptm1(-1, 0, 0, game) + ptm2(game->pos_p.x, game->pos_p.y, game));
}

int	ptm1(int j, int e, int p, t_game *game)
{
	int	i;

	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			if ((j == 0 || j == game->size.y || i == 0 || i == game->size.x)
				&& game->map[j][i] != '1')
				return (1);
			if (game->map[j][i] == 'C')
				game->n_c++;
			if (game->map[j][i] == 'P')
			{
				p++;
				game->pos_p = (t_point){i, j};
			}
			if (game->map[j][i] == 'T')
				handle_turtle(i, j, game);
			if (game->map[j][i] == 'E')
				e++;
		}
	}
	return (p != 1 || e != 1 || game->n_c < 1 || game->size.y < 2
		|| game->size.y > 14 || game->size.x > 29);
}

int	ptm2(int x, int y, t_game *game)
{
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'F' || x <= 0
		|| x >= game->size.x || y <= 0 || y >= game->size.y
		|| game->map_copy[y][x] == 'A')
		return (1);
	else if (game->map_copy[y][x] == 'C')
		game->temp++;
	else if (game->map_copy[y][x] == 'E')
		game->n_e++;
	game->map_copy[y][x] = 'F';
	ptm2(x - 1, y, game);
	ptm2(x + 1, y, game);
	ptm2(x, y - 1, game);
	ptm2(x, y + 1, game);
	return (!(game->temp == game->n_c && game->n_e == 1));
}

void	copy_the_map(t_game *game)
{
	int		count;
	int		i;

	count = 0;
	while (game->map[count])
		count++;
	game->map_copy = malloc((count + 1) * sizeof(char *));
	if (!game->map_copy)
		exit_so_long(game, "Error :\nmalloc failed");
	i = -1;
	while (game->map[++i])
	{
		game->map_copy[i] = strdup(game->map[i]);
		if (!game->map_copy[i])
		{
			while (i-- > 0)
				free(game->map_copy[i]);
			free(game->map_copy);
			exit_so_long(game, "Error :\nmalloc failed");
		}
	}
	game->map_copy[i] = NULL;
}
