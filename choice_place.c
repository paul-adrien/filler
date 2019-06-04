/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:54:16 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 17:57:23 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_asset	count_score(t_asset asset, int y, int x, int i)
{
	int		j;

	j = 0;
	asset.score = 0;
	while (asset.piece[i] && asset.piece[i][j] != '\0')
	{
		if (y >= asset.y_max)
			return (asset);
		if (asset.piece[i][j] == '*' && asset.heat_map[y][x])
			asset.score = asset.score + asset.heat_map[y][x];
		if (asset.piece[i] && asset.piece[i][j + 1] && x + 1 < asset.x_max)
		{
			j++;
			x++;
		}
		else
		{
			i++;
			y++;
			x = x - j + 1;
			j = 0;
		}
	}
	return (asset);
}

static int		check_nb_wildcards(t_asset asset, int y, int x, int i)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (asset.piece[k] && asset.piece[k][l] != '\0')
	{
		if (asset.piece[k][l] == '*' && (asset.map[y][x] == asset.player))
			i++;
		if (asset.piece[k][l] == '*' && asset.map[y][x] == '\0')
			return (1);
		if (asset.piece[k] && asset.piece[k][l + 1])
		{
			l++;
			x++;
		}
		else
		{
			k++;
			y++;
			x = x - l;
			l = 0;
		}
	}
	return (i);
}

static int		check_placing(t_asset asset, int y, int x, int k)
{
	int		l;

	l = 0;
	while (asset.piece[k] && asset.piece[k][l] != '\0')
	{
		if ((asset.piece[k][l] == '.') || ((asset.piece[k][l] == '*')
				&& (asset.map[y] && asset.map[y][x] != '\0'
				&& asset.map[y][x] != asset.adv && (asset.map[y][x] == '.'
				|| asset.map[y][x] == asset.player))))
		{
			if (asset.piece[k] && asset.piece[k][l++ + 1])
				x++;
			else
			{
				k++;
				y++;
				x = x - l + 1;
				l = 0;
			}
		}
		else if (asset.piece[k][l] == '*')
			break ;
	}
	return (k);
}

t_asset			choice_place(t_asset asset, int y, int x)
{
	int		k;

	if (x >= 0 && y >= 0)
	{
		k = check_placing(asset, y, x, 0);
		if (!asset.piece[k] && check_nb_wildcards(asset, y, x, 0) <= 1)
		{
			if (asset.end >= 4 && x > 0 && y > 0)
			{
				asset.tmp_x = x;
				asset.tmp_y = y;
				return (asset);
			}
			asset = count_score(asset, y, x, 0);
			if ((asset.score == 0 && asset.tmp_score == 0)
					|| asset.score < asset.tmp_score
					|| asset.tmp_score == 0)
			{
				asset.tmp_x = x;
				asset.tmp_y = y;
				asset.tmp_score = asset.score;
			}
		}
	}
	return (asset);
}
