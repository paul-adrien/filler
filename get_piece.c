/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:25:16 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:09:49 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		piece_info(t_asset *asset)
{
	char	**tab;
	char	*line;

	tab = NULL;
	if (get_next_line(0, &line, 0) != 1)
		return (1);
	if (!(tab = ft_strsplit(line, ' ')))
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	asset->y_pmax = ft_atoi(tab[1]);
	asset->x_pmax = ft_atoi(tab[2]);
	free_tab(&tab);
	if (asset->y_pmax <= 0 || asset->x_pmax <= 0)
		return (1);
	return (0);
}

int		get_piece(t_asset *asset)
{
	char	*line;
	int		i;

	i = 0;
	if (!(asset->piece = (char **)malloc(sizeof(char *) * (asset->y_pmax + 1))))
		return (1);
	while (i <= asset->y_pmax - 1)
	{
		if ((get_next_line(0, &line, 0)) != 1)
		{
			while (i > 0)
				free(asset->piece[i--]);
			free(asset->piece);
			asset->piece = NULL;
			return (1);
		}
		if (!(asset->piece[i++] = ft_strsub(line, 0, asset->x_pmax)))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	asset->piece[i] = NULL;
	return (0);
}
