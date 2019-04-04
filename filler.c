/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/04 15:19:28 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static char	**get_map()
{
	int		fd;
	int		size[2];
	char	*line;
	int		i;
	char	**map;

	i = 0;
	fd = 0;
	get_next_line(fd, &line, 0);
	if (line[10] <= '9' && line[10] >= '0')
		size[0] = (line[8] - '0') * 100 + (line[9] - '0') * 10 + (line[10] - '0');
	else
		size[0] = (line[8] - '0') * 10 + (line[9] - '0');
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

static t_asset	get_player(t_asset asset)
{
	char	*line;
	int		fd;
	char	player;

	fd = 0;
	get_next_line(fd, &line, 0);
	player = line[10];
	if (player == '2')
	{
		asset.player = 'X';
		asset.adv = 'O';
	}
	else
	{
		asset.player = 'O';
		asset.adv = 'X';
	}
	return (asset);
}

static char	**get_piece()
{
	char	*line;
	int		i;
	int		j;
	int		fd;
	char	**piece;

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

static t_asset	find_last_p(t_asset asset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	asset.last_p = malloc(sizeof(int) * 2);
	asset.last_p[0] = 0;
	asset.last_p[1] = 0;
	while (asset.lmap && asset.map[y] && asset.lmap[y])
	{
		if (asset.map[y][x] != asset.lmap[y][x])
		{
			asset.last_p[0] = y;
			asset.last_p[1] = x;
			//ft_putnbr(asset.last_p[0]);
			//ft_putnbr(asset.last_p[1]);
			return (asset);
		}
		if (asset.map[y] && asset.map[y][x + 1])
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
	//ft_putnbr(asset.last_p[0]);
	//ft_putnbr(asset.last_p[1]);
	return (asset);
}

static t_asset	ft_print_res(t_asset asset)
{
	ft_putnbr(asset.res[0]);
	write(1, " ", 1);
	ft_putnbr(asset.res[1] - 4);
	write(1, "\n", 1);
	asset.res[0] = 0;
	asset.res[1] = 0;
	return (asset);
}

/*void	ft_test(t_asset asset)
{
	FILE* fichier = NULL;
	int		i = 0;

	fichier = fopen("test.txt", "w");

	if (fichier != NULL)
	{
		while (i++ <= 23)
			fprintf(fichier, "%s\n", asset.map[i]);
		fclose(fichier);
	}
}*/

int		main(void)
{
	t_asset	asset;
	int		i;

	i = 1;
	asset = get_player(asset);
	//asset.size_map = get_size();
	while (i)
	{
		//asset.res = malloc(sizeof(int) * 2);
		//asset.res[0] = 0;
		//asset.res[1] = 0;
		asset.map = get_map();
		//write(1, "test", 4);
		asset.piece = get_piece();
		//write(1, "test2", 5);
		//ft_test(asset);
		asset = find_last_p(asset);
		//write(1, "test3", 5);
		asset = ft_pos_map(asset, 0, 4);
		//write(1, "test4", 5);
		//sleep(1);
		asset = ft_print_res(asset);
		asset.lmap = asset.map;
	}
	return (0);
}
