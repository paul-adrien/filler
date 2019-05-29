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
	//if (asset.line) peut etre pas necessaire
		//ft_strdel(&asset.line);
	asset.tmp_score = 0;
	return (asset);
}

int		main(void)
{
	t_asset	asset;

	asset_init(&asset);
	if (get_player(&asset) == 1)
		return (1);
	while (1)
	{
		if (map_info(&asset) == 1)
			exit(1);
			//put_error(NULL, NULL, asset.line, NULL);
		if (get_map(&asset) == 1)
			exit(1);
			//put_error(asset.map, NULL, NULL, NULL);
		if (piece_info(&asset) == 1)
			exit(1);
			//put_error(asset.map, NULL, asset.line, NULL);
		if (get_piece(&asset) == 1)
			exit(1);
			//put_error(asset.map, asset.piece, NULL, NULL);
		if (create_heat_map(&asset) == 1)
			exit(1);
			//put_error(asset.map, asset.piece, NULL, asset.heat_map);
		asset = init_heat_map(asset);
		asset = find_place(asset, 0, 0);
		asset = ft_print_res(asset);
		asset = sp_free_all(asset);
	}
	return (0);
}
