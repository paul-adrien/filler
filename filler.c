/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/30 15:45:13 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int	get_map(t_asset *asset)
{
	int		fd;
	char	**tab;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	if (get_next_line(fd, &line, 0) == -1)
		return (1);
	if (!(tab = ft_strsplit(line, ' ')))
		return (1);
	asset->y_max = ft_atoi(tab[1]);
	asset->x_max = ft_atoi(tab[2]);
	if (!(asset->map = (char **)malloc(sizeof(char *) * asset->y_max + 1)))
		return (1);
	if (get_next_line(fd, &line, 0) == -1)
		return (1);
	free(line);
	while (i <= asset->y_max - 1)
	{
		if (get_next_line(fd, &line, 0) == -1)
			return (1);
		if (!(asset->map[i++] = ft_strsub(line, 4, asset->x_max)))
			return (1);
		free(line);
	}
	asset->map[i] = NULL;
	free(tab);
	return (0);
}

static int		get_player(t_asset *asset)
{
	char	*line;
	int		fd;
	char	player;

	fd = 0;
	if (!(get_next_line(fd, &line, 0)))
		return (1);
	player = line[10];
	if (player == '2')
	{
		asset->player = 'X';
		asset->adv = 'O';
	}
	else
	{
		asset->player = 'O';
		asset->adv = 'X';
	}
	free(line);
	return (0);
}

static int	get_piece(t_asset *asset)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	fd = 0;
	i = 0;
	j = 0;
	if (!(get_next_line(fd, &line, 0)))
		return (1);
	i = line[6] - '0';
	free(line);
	asset->piece = (char **)malloc(sizeof(char *) * i + 1);
	if (!asset->piece)
		return (1);
	while (i-- > 0)
	{
		if (get_next_line(fd, &line, 0) == -1)
			return (1);
		asset->piece[j++] = line;
	}
	free(line);
	asset->piece[j] = NULL;
	return (0);
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

static void		asset_init(t_asset *asset)
{
	asset->x = 0;
	asset->y = 0;
	asset->x_max = 0;
	asset->y_max = 0;
	asset->score = 0;
	asset->tmp_score = 0;
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
				fprintf(fichier, "%d", asset.heat_map[i][j]);
				//ft_putnbr(asset.heat_map[i][j]);
				j++;
			}
			fprintf(fichier, "\n");
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
	free(asset.piece);
	asset.tmp_score = 0;
	return (asset);
}

int		main(void)
{
	t_asset		asset;
	int		i;

	i = 1;
	asset_init(&asset);
	if (get_player(&asset) == 1)
		return (1);
	while (i)
	{
		if (get_map(&asset) == 1)
			return (1);
		if (get_piece(&asset) == 1)
			return (1);
		asset = create_heat_map(asset);
		asset = ft_pos_map(asset, 0, 0);
		asset = ft_print_res(asset);
		ft_test(asset);
		asset = ft_free_all(asset);
	}
	return (0);
}
