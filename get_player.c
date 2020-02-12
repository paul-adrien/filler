/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:09:59 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:20:14 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	test_line(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 5)
		return (0);
	if (ft_strcmp(tab[0], "$$$") != 0 || ft_strcmp(tab[1], "exec") != 0
		|| ft_strcmp(tab[3], ":") != 0
		|| ft_strstr(tab[4], "plaurent.filler]") == 0)
		return (0);
	return (1);
}

int			get_player(t_asset *asset)
{
	if (get_next_line(0, &asset->line, 0) != 1
		|| !(asset->tab = ft_strsplit(asset->line, ' ')))
	{
		ft_strdel(&asset->line);
		return (1);
	}
	ft_strdel(&asset->line);
	if (test_line(asset->tab) == 0)
	{
		free_tab(&asset->tab);
		return (1);
	}
	if (ft_strcmp(asset->tab[2], "p2") == 0)
	{
		asset->player = 'X';
		asset->adv = 'O';
	}
	else if (ft_strcmp(asset->tab[2], "p1") != 0)
	{
		free_tab(&asset->tab);
		return (1);
	}
	free_tab(&asset->tab);
	return (0);
}
