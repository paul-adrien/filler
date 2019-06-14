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

static int	test_line(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (0);
	if (ft_strcmp(tab[0], "Piece") != 0)
		return (0);
	return (1);
}

int			piece_info(t_asset *asset)
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
	if (test_line(tab) != 1)
	{
		free_tab(&tab);
		return (1);
	}
	asset->y_pmax = ft_atoi(tab[1]);
	asset->x_pmax = ft_atoi(tab[2]);
	free_tab(&tab);
	if (asset->y_pmax <= 0 || asset->x_pmax <= 0)
		return (1);
	return (0);
}

static int	test_line2(char *line, int x_pmax)
{
	int		i;

	i = -1;
	while (line[++i])
		if ((line[i] != '.' && line[i] != '*') || i > x_pmax)
			return (0);
	if ( i != x_pmax)
		return (0);
	return (1);
}

int			get_piece(t_asset *asset)
{
	char	*line;
	int		i;

	i = 0;
	if (!(asset->piece = (char **)malloc(sizeof(char *) * (asset->y_pmax + 1))))
		return (1);
	while (i <= asset->y_pmax - 1)
	{
		if ((get_next_line(0, &line, 0)) != 1)
			return (1);
		if (test_line2(line, asset->x_pmax) != 1)
		{
			ft_strdel(&line);
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
