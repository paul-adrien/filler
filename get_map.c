/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:21:15 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		map_info(t_asset *asset)
{
	if ((get_next_line(0, &asset->line, 0) != 1))
		return (1);
	if (!(asset->tab = ft_strsplit(asset->line, ' ')))
	{
		ft_strdel(&asset->line);
		return (1);
	}
	ft_strdel(&asset->line);
	if (ft_strcmp(asset->tab[0], "Plateau") != 0)
	{
		free_tab(&asset->tab);
		return (1);
	}
	asset->y_max = ft_atoi(asset->tab[1]);
	asset->x_max = ft_atoi(asset->tab[2]);
	free_tab(&asset->tab);
	if (asset->y_max <= 0 || asset->x_max <= 0)
		return (1);
	if (get_next_line(0, &asset->line, 0) != 1)
	{
		free(asset->map);
		return (1);
	}
	ft_strdel(&asset->line);
	return (0);
}

int		get_map(t_asset *asset)
{
	int		i;
	char	*line;
	int		res;

	i = 0;
	res = 0;
	if (!(asset->map = (char **)malloc(sizeof(char *) * (asset->y_max + 1))))
		return (1);
	while (i <= asset->y_max - 1)
	{
		if ((res = get_next_line(0, &line, 0)) != 1)
		{
			while (i > 0 && asset->map[i])
				free(asset->map[--i]);
			free(asset->map);
			asset->map = NULL;
			return (1);
		}
		if (!(asset->map[i++] = ft_strsub(line, 4, asset->x_max)))
			return (1);
		ft_strdel(&line);
	}
	asset->map[i] = NULL;
	return (0);
}
