/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:28:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/06/24 15:17:13 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_asset	test(t_asset a, int y, int x)
{
	if (x + 1 < a.x_max && a.map[y][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	else if (x - 1 > 0 && a.map[y][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	else if (y + 1 < a.y_max && a.map[y + 1][x] == a.adv)
		a.heat_map[y][x] = 1;
	else if (y - 1 > 0 && a.map[y - 1][x] == a.adv)
		a.heat_map[y][x] = 1;
	else if (x + 1 < a.x_max && y + 1 < a.y_max && a.map[y + 1][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	else if (x + 1 < a.x_max && y - 1 > 0 && a.map[y - 1][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	else if (x - 1 > 0 && y - 1 > 0 && a.map[y - 1][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	else if (x - 1 > 0 && y + 1 < a.y_max && a.map[y + 1][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	return (a);
}

static t_asset	test2(t_asset a, int y, int x, int i)
{
	if (x + 1 < a.x_max && a.heat_map[y][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	else if (x - 1 > 0 && a.heat_map[y][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	else if (y + 1 < a.y_max && a.heat_map[y + 1][x] == i)
		a.heat_map[y][x] = i + 1;
	else if (y - 1 > 0 && a.heat_map[y - 1][x] == i)
		a.heat_map[y][x] = i + 1;
	else if (x + 1 < a.x_max
			&& y + 1 < a.y_max && a.heat_map[y + 1][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	else if (x + 1 < a.x_max && y - 1 > 0 && a.heat_map[y - 1][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	else if (x - 1 > 0 && y - 1 > 0 && a.heat_map[y - 1][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	else if (x - 1 > 0 && y + 1 < a.y_max && a.heat_map[y + 1][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	return (a);
}

static t_asset	fill_heat_map(t_asset asset, int x, int y)
{
	int		i;
	int		n;

	i = 1;
	n = 1;
	if (asset.x_max * asset.y_max > 900)
		n = 2;
	while (i < ((asset.x_max * asset.y_max) / n))
	{
		while (y < asset.y_max)
		{
			while (x < asset.x_max)
			{
				if (asset.heat_map[y][x] == 0)
					asset = test2(asset, y, x, i);
				x++;
			}
			x = 0;
			y++;
		}
		x = 0;
		y = 0;
		i++;
	}
	return (asset);
}

t_asset			init_heat_map(t_asset asset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < asset.y_max)
	{
		while (x < asset.x_max)
		{
			if (asset.map[y][x] == '.')
			{
				asset.heat_map[y][x] = 0;
				asset = test(asset, y, x);
			}
			else if (asset.map[y][x] == asset.player && asset.heat_map[y][x])
				asset.heat_map[y][x] = -1;
			else if (asset.map[y][x] == asset.adv && asset.heat_map[y][x])
				asset.heat_map[y][x] = -2;
			x++;
		}
		x = 0;
		y++;
	}
	asset = fill_heat_map(asset, 0, 0);
	return (asset);
}

int				create_heat_map(t_asset *a)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (!(a->heat_map = (int **)malloc(sizeof(int *) * (a->y_max + 1))))
		return (1);
	while (i <= a->y_max - 1)
		if (!(a->heat_map[i++] = (int *)malloc(sizeof(int) * (a->x_max + 1))))
			return (1);
	y = 0;
	while (y < a->y_max)
	{
		x = 0;
		while (x < a->x_max + 1)
		{
			a->heat_map[y][x] = 0;
			x++;
		}
		y++;
	}
	a->heat_map[i] = NULL;
	return (0);
}
