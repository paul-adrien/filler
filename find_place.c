/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:08:58 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:16:18 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		st_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (--i);
}

static int	*ft_pos_piece(char **piece, int *pos)
{
	int		k;
	int		l;

	k = pos[0];
	l = pos[1];
	while (piece[k][l] && piece[k][l] != '*')
	{
		l++;
		if (!piece[k][l])
		{
			k++;
			l = 0;
		}
		if (!piece[k])
			return (0);
	}
	if (piece[k][l] && piece[k][l] == '*')
	{
		pos[0] = k;
		pos[1] = l;
		return (pos);
	}
	return (0);
}

static t_asset	check_place(t_asset asset, int i, int j)
{
	int		*coord;

	if (!(coord = (int *)malloc(sizeof(int) * 3)))
	{
		asset.error = 1;
		return (asset);
	}
	coord[0] = 0;
	coord[1] = 0;
	while ((coord = ft_pos_piece(asset.piece, coord)))
	{
		asset.y = i - coord[0];
		asset.x = j - coord[1];
		asset = new_place(asset, asset.y, asset.x);
		if (asset.piece[coord[0]][coord[1]] && asset.piece[coord[0]][coord[1] + 1])
			coord[1] = coord[1] + 1;
		else if (asset.piece[coord[0]] && asset.piece[coord[0] + 1])
		{
			coord[1] = 0;
			coord[0] = coord[0] + 1;
		}
		else
			return (asset);
	}
	return (asset);
}

t_asset			find_place(t_asset asset, int i, int j)
{
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
		if (asset.error == 1)
			return (asset);
		return (find_place(asset, i, j = j + 1));
	}
	else
		return (asset);
}
