/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/26 11:26:47 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static char	**get_map(char **map)
{
	int		fd;
	int		size[2];
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	get_next_line(fd, &line, 0);
	size[0] = (line[8] - '0') * 10 + (line[9] - '0');
	size[1] = (line[11] - '0') * 10 + (line[12] - '0');
	map = (char **)malloc(sizeof(char *) * size[0] + 1);
	get_next_line(fd, &line, 0);
	free(line);
	while (i <= size[0] - 1)
	{
		get_next_line(fd, &line, 0);
		map[i++] = line;
	}
	map[i] = NULL;
	return (map);
}

static int	get_player(int	player)
{
	char	*line;
	int		fd;

	fd = 0;
	get_next_line(fd, &line, 0);
	player = line[10] - '0';
	return (player);
}

static char	**get_piece(char **piece)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	fd = 0;
	i = 0;
	j = 0;
	get_next_line(fd, &line, 0);
	i = line[6] - '0';
	piece = (char **)malloc(sizeof(char *) * i + 1);
	while (i-- > 0)
	{
		get_next_line(fd, &line, 0);
		piece[j++] = line;
	}
	piece[j] = NULL;
	return (piece);
}

int		main(void)
{
	int		player;
	char	**map;
	char	**piece;
	int		i;

	i = 1;
	player = get_player(player);
	while (i)
	{
		map = get_map(map);
		piece = get_piece(piece);
		ft_pos_map(map, piece, 0, 4);
	}
	free(map);
	free(piece);
	return (0);
}
