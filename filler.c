/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/18 18:34:31 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static t_asset	get_map(t_asset asset)
{
	int		fd;
	char	**tab;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	get_next_line(fd, &line, 0);
	tab = ft_strsplit(line, ' ');
	asset.y_max = ft_atoi(tab[1]);
	asset.x_max = ft_atoi(tab[2]);
	asset.map = (char **)malloc(sizeof(char *) * asset.y_max + 1);
	get_next_line(fd, &line, 0);
	free(line);
	while (i <= asset.y_max - 1)
	{
		get_next_line(fd, &line, 0);
		asset.map[i++] = ft_strsub(line, 4, asset.x_max);
	}
	asset.map[i] = NULL;
	free(tab);
	return (asset);
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

/*static t_asset	find_last_p(t_asset asset)
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
}*/

static t_asset		asset_init(t_asset asset)
{
	asset.x = 0;
	asset.y = 0;
	//asset.tmp_x = 0;
	//asset.tmp_y = 0;
	asset.x_max = 0;
	asset.y_max = 0;
	asset.score = 0;
	asset.tmp_score = 0;
	return (asset);
}

static t_asset	ft_print_res(t_asset asset)
{
	ft_putnbr(asset.tmp_y);
	write(1, " ", 1);
	ft_putnbr(asset.tmp_x);
	write(1, "\n", 1);
	return (asset);
}

void	ft_test(t_asset asset)
{
	FILE* fichier = NULL;
	int		i = 0;
	int		j = 0;

	fichier = fopen("test.txt", "w");

	if (fichier != NULL)
	{
		while (i <= asset.y_max)
		{
			while (j <= asset.x_max)
			{
				fprintf(fichier, "%d\n", asset.heat_map[i][j]);
				//ft_putnbr(asset.heat_map[i][j]);
				j++;
			}
			//ft_putstr(asset.map[i]);
			//ft_putchar('\n');
			j = 0;
			i++;
		}
		fclose(fichier);
	}
}

static t_asset	ft_free_all(t_asset asset)
{
	free(asset.map);
	free(asset.heat_map);
	//free(line);
	free(asset.piece);
	asset.tmp_score = 0;
	return (asset);
}

int		main(void)
{
	t_asset	asset;
	int		i;

	i = 1;
	asset = asset_init(asset);
	asset = get_player(asset);
	while (i)
	{
		asset = get_map(asset);
		asset.piece = get_piece();
		asset = create_heat_map(asset);
		//asset = find_last_p(asset);
		asset = ft_pos_map(asset, 0, 0);
		asset = ft_print_res(asset);
		//asset.lmap = asset.map;
		ft_test(asset);
		asset = ft_free_all(asset);
	}
	return (0);
}
