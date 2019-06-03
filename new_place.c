/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:08:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:29:12 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_asset	count_score(t_asset asset, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	asset.score = 0;
	while (asset.piece[i] && asset.piece[i][j] != '\0')
	{
		if (asset.piece[i][j] == '*')
			asset.score = asset.score + asset.heat_map[y][x];
		if (asset.piece[i] && asset.piece[i][j + 1])
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

static int	check2(t_asset asset, int y, int x, int i)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (asset.piece[k] && asset.piece[k][l] != '\0')
	{
		if (asset.piece[k][l] == '*' && (asset.map[y][x] == asset.player || asset.map[y][x] == (asset.player + 32)))
			i++;
		if (asset.piece[k][l] == '*' && asset.map[y][x] == '\0')
			return(2);
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

static int		check(t_asset asset, int y, int x, int k)
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

t_asset			new_place(t_asset asset, int y, int x)
{
	int		k;

	if (x >= 0 && y >= 0)
	{
		k = check(asset, y, x, 0);
		if (!asset.piece[k] && check2(asset, y, x, 0) <= 1)
		{
			if (asset.end == 1)
			{
				asset.tmp_x = x;
				asset.tmp_y = y;
				asset.end = 2;
			}
			asset = count_score(asset, y, x);
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
