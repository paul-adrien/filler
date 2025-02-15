/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:07:29 by plaurent          #+#    #+#             */
/*   Updated: 2019/06/04 10:57:37 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_pos_piece(t_asset *asset)
{
	int		k;
	int		l;

	k = asset->c1;
	l = asset->c2;
	while (asset->piece[k][l] && asset->piece[k][l] != '*')
	{
		l++;
		if (!asset->piece[k][l])
		{
			k++;
			l = 0;
		}
		if (!asset->piece[k])
			return (0);
	}
	if (asset->piece[k][l] && asset->piece[k][l] == '*')
	{
		asset->c1 = k;
		asset->c2 = l;
		return (1);
	}
	return (0);
}

static t_asset	check_place(t_asset asset, int i, int j)
{
	asset.c1 = 0;
	asset.c2 = 0;
	while (ft_pos_piece(&asset))
	{
		asset.y = i - asset.c1;
		asset.x = j - asset.c2;
		asset = choice_place(asset, asset.y, asset.x);
		if (asset.end >= 4 && asset.tmp_x > 0 && asset.tmp_y > 0)
			break ;
		if (asset.piece[asset.c1][asset.c2]
			&& asset.piece[asset.c1][asset.c2 + 1])
			asset.c2 = asset.c2 + 1;
		else if (asset.piece[asset.c1] && asset.piece[asset.c1 + 1])
		{
			asset.c2 = 0;
			asset.c1 = asset.c1 + 1;
		}
		else
			return (asset);
	}
	return (asset);
}

t_asset			find_place(t_asset asset, int i, int j)
{
	if (asset.end >= 4 && asset.tmp_x > 0 && asset.tmp_y > 0)
		return (asset);
	if (asset.map[i] && asset.map[i][j] != asset.player)
	{
		if (asset.map[i][j] == '.' || asset.map[i][j] == asset.adv
				|| asset.map[i][j] == (asset.adv + 32))
			return (find_place(asset, i, j = j + 1));
		else
			return (find_place(asset, i = i + 1, 0));
	}
	else if (asset.map[i])
	{
		asset = check_place(asset, i, j);
		return (find_place(asset, i, j = j + 1));
	}
	else
		return (asset);
}
