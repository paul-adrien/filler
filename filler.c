/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/06/04 10:56:16 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		asset_init(t_asset *asset)
{
	asset->heat_map = NULL;
	asset->map = NULL;
	asset->line = NULL;
	asset->piece = NULL;
	asset->tab = NULL;
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
	asset->tmp_x = 0;
	asset->tmp_y = 0;
	asset->end = 0;
}

static t_asset	ft_print_res(t_asset asset)
{
	if (asset.tmp_x < 0)
		asset.tmp_x = asset.x_max + asset.tmp_x - 1;
	if (asset.tmp_y < 0)
		asset.tmp_y = asset.y_max + asset.tmp_y - 1;
	ft_putnbr(asset.tmp_y);
	write(1, " ", 1);
	ft_putnbr(asset.tmp_x);
	write(1, "\n", 1);
	return (asset);
}

static t_asset	free_all(t_asset asset)
{
	if (asset.map)
	{
		free_tab(&asset.map);
		asset.map = NULL;
	}
	if (asset.heat_map)
	{
		//free(asset.heat_map);
		ft_inttabdel(&asset.heat_map);
		//asset.heat_map = NULL;
	}
	if (asset.piece)
	{
		free_tab(&asset.piece);
		//asset.piece = NULL;
	}
	if (asset.tmp_score <= 0)
		asset.end = asset.end + 1;
	asset.tmp_score = 0;
	asset.tmp_x = 0;
	asset.tmp_y = 0;
	return (asset);
}

int				main(void)
{
	t_asset	asset;

	asset_init(&asset);
	if (get_player(&asset) == 1)
		return (-1 * get_next_line(0, NULL, 1));
	while (1)
	{
		if (map_info(&asset) == 1 || get_map(&asset) == 1)
			break ;
		if (piece_info(&asset) == 1 || get_piece(&asset) == 1)
			break ;
		if (asset.score >= 0 && asset.end < 4)
			if (create_heat_map(&asset) == 1)
				break ;
		if (asset.score >= 0 && asset.end < 4)
			asset = init_heat_map(asset);
		asset = find_place(asset, 0, 0);
		asset = ft_print_res(asset);
		asset = free_all(asset);
	}
	last_free(asset.map, asset.piece, asset.line, asset.heat_map);
	return (0);
}
