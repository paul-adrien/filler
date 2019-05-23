/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:25:16 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:03:16 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		piece_info(t_asset *asset)
{
	char	**tab;

	tab = NULL;
	if (get_next_line(0, &asset->line, 0) != 1)
		return (1);
	if (!(tab = ft_strsplit(asset->line, ' ')))
	{
		free(asset->line);
		return (1);
	}
	ft_strdel(&asset->line);
	//if (ft_strcmp(asset->tab[0], "Piece") != 0) prblm pour la map 02
	//{
	//	free_tab(&asset->tab);
	//	return (1);
	//}
	asset->y_pmax = ft_atoi(tab[1]);
	asset->x_pmax = ft_atoi(tab[2]);
	free_tab(&tab);
	if (asset->y_pmax <= 0 || asset->x_pmax <= 0)
		return (1);
	return  (0);
}

int		get_piece(t_asset *asset)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!(asset->piece = (char **)malloc(sizeof(char *) * asset->y_pmax + 1)))
		return (1);
	while (i <= asset->y_pmax - 1)
	{
		if ((res = get_next_line(0, &line, 0)) != 1)
		{
			if (res == 0)
				free(line);
			while (i > 0)
				free(asset->piece[i--]);
			free(asset->piece);
			asset->piece = NULL;
			return (1);
		}
		//if (check_line(asset, &line, i) == 1)
		//	return (1);
		if (!(asset->piece[i++] = ft_strsub(line, 0, asset->x_pmax)))
			return (0);
		free(line);
	}
	asset->piece[i] = NULL;
	return (0);
}
