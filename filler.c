/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:06:34 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*static t_asset	find_last_p(t_asset asset)
{
	int		x;
	int		y;
	x = 0;
	y = 0;
	asset.last_p = malloc(sizeof(int) * 2);
	asset.last_p2 = malloc(sizeof(int) * 2);
	asset.last_p2[0] = 0;
	asset.last_p2[1] = 0;
	asset.last_p[0] = 0;
	asset.last_p[1] = 0;
	while (asset.lmap && asset.map[y] && asset.lmap[y])
	{
		if (asset.map[y][x] != asset.lmap[y][x] && asset.map[y][x] == asset.player)
		{
			asset.last_p2[0] = y;
			asset.last_p2[1] = x;
		}
		if (asset.map[y][x] != asset.lmap[y][x] && asset.map[y][x] == asset.adv)
		{
			asset.last_p[0] = y;
			asset.last_p[1] = x;
		}
		if (asset.map[y] && asset.map[y][x + 1])
			x++;
		else
		{
			y++;
			x = 0;
		}
		if (asset)
	}
	return (asset);
}*/

static void		asset_init(t_asset *asset)
{
	asset->line = NULL;
	asset->player = 'O';
	asset->adv = 'X';
	asset->x = 0;
	asset->y = 0;
	asset->y_pmax = 0;
	asset->x_pmax = 0;
	asset->x_max = 0;
	asset->y_max = 0;
	asset->score = 0;
	asset->tmp_score = 0;
	asset->error = 0;
}

static t_asset	ft_print_res(t_asset asset)
{
	ft_putnbr(asset.tmp_y);
	write(1, " ", 1);
	ft_putnbr(asset.tmp_x);
	write(1, "\n", 1);
	return (asset);
}

static t_asset	sp_free_all(t_asset asset)
{
	if (asset.map)
	{
		free(asset.map);
		asset.map = NULL;
	}
	if (asset.heat_map)
	{
		free(asset.heat_map);
		asset.heat_map = NULL;
	}
	if (asset.piece)
	{
		free(asset.piece);
		asset.piece = NULL;
	}
	asset.tmp_score = 0;
	return (asset);
}

int		main(void)
{
	t_asset	asset;

	asset_init(&asset);
	get_player(&asset);
	while (1)
	{
		if (map_info(&asset) == 1)
			return (1);
		if (get_map(&asset) == 1)
			return (1);
		if (piece_info(&asset) == 1)
			return (1);
		if (get_piece(&asset) == 1)
			return (1);
		if (create_heat_map(&asset) == 1)
			return (1);
		asset = init_heat_map(asset);
		asset = find_place(asset, 0, 0);
		if (asset.error == 1)
			return (1);
		asset = ft_print_res(asset);
		asset = sp_free_all(asset);
	}
	return (0);
}
