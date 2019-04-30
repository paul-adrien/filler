/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:28:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/30 15:41:55 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static t_asset	test(t_asset a, int y, int x)
{
//	ft_putchar(a.adv);
//	ft_putnbr(x);
//	ft_putnbr(y);
	if (x + 1 < a.x_max && a.map[y][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	if (x - 1 > 0 && a.map[y][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	if (y + 1 < a.y_max && a.map[y + 1][x] == a.adv)
		a.heat_map[y][x] = 1;
	if (y - 1 > 0 && a.map[y - 1][x] == a.adv)
		a.heat_map[y][x] = 1;
	if (x + 1 < a.x_max && y + 1 < a.y_max && a.map[y + 1][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	if (x + 1 < a.x_max && y - 1 > 0 && a.map[y - 1][x + 1] == a.adv)
		a.heat_map[y][x] = 1;
	if (x - 1 > 0 && y - 1 > 0 && a.map[y - 1][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	if (x - 1 > 0 && y + 1 < a.y_max && a.map[y + 1][x - 1] == a.adv)
		a.heat_map[y][x] = 1;
	return(a);
}

static t_asset	test2(t_asset a, int y, int x, int i)
{
	if (x + 1 < a.x_max && a.heat_map[y][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	if (x - 1 > 0 && a.heat_map[y][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	if (y + 1 < a.y_max && a.heat_map[y + 1][x] == i)
		a.heat_map[y][x] = i + 1;
	if (y - 1 > 0 && a.heat_map[y - 1][x] == i)
		a.heat_map[y][x] = i + 1;
	if (x + 1 < a.x_max && y + 1 < a.y_max && a.heat_map[y + 1][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	if (x + 1 < a.x_max && y - 1 > 0 && a.heat_map[y - 1][x + 1] == i)
		a.heat_map[y][x] = i + 1;
	if (x - 1 > 0 && y - 1 > 0 && a.heat_map[y - 1][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	if (x - 1 > 0 && y + 1 < a.y_max && a.heat_map[y + 1][x - 1] == i)
		a.heat_map[y][x] = i + 1;
	return (a);
}

static t_asset	init_heat_map2(t_asset asset)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 1;
	while (i < asset.x_max)
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

static t_asset	init_heat_map(t_asset asset)
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
			if (asset.map[y][x] == asset.player)
				asset.heat_map[y][x] = -1;
			if (asset.map[y][x] == asset.adv)
				asset.heat_map[y][x] = -2;
			x++;
		}
		x = 0;
		y++;
	}
	return (asset);
}

t_asset		create_heat_map(t_asset asset)
{
	int		i;

	i = 0;
	if (!(asset.heat_map = (int **)malloc(sizeof(int *) * asset.y_max + 1)))
		exit(0);
	while (i < asset.x_max)
	{
		if (!(asset.heat_map[i++] = (int *)malloc(sizeof(int) * asset.x_max + 1)))
		exit(0);
	}
	asset = init_heat_map(asset);
	asset = init_heat_map2(asset);
	return (asset);
}
