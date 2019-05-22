/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/18 18:34:31 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static char	**test_line(char **tab)
{
	if (ft_strcmp(tab[0], "$$$") != 0 || ft_strcmp(tab[1], "exec") != 0
		|| ft_strcmp(tab[3], ":") != 0
		|| ft_strcmp(tab[4], "[players/plaurent.filler]") != 0)
		tab[2] = "er";
	return (tab);
}

int		get_player(t_asset *asset, char *line)
{
	if (get_next_line(0, &line, 0) != 1)
		return (1);
	if (!(asset->tab = ft_strsplit(line, ' ')))
	{
		free(line);
		return (1);
	}
	free(line);
	asset->tab = test_line(asset->tab);
	if (ft_strcmp(asset->tab[2], "p2") == 0)
	{
		asset->player = 'X';
		asset->adv = 'O';
	}
	else if (ft_strcmp(asset->tab[2], "p1") == 0)
	{
		asset->player = 'O';
		asset->adv = 'X';
	}
	else
	{
		free_tab(&asset->tab);
		return (1);
	}
	free_tab(&asset->tab);
	return (0);
}
