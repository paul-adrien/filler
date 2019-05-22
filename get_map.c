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

int		map_info(t_asset *asset, char *line)
{
	if ((get_next_line(0, &line, 0) != 1))
		return (1);
	if (!(asset->tab = ft_strsplit(line, ' ')))
	{
		free(line);
		return (1);
	}
	free(line);
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
	if (!(asset->map = (char **)malloc(sizeof(char *) * asset->y_max + 1)))	
		return (1);
	if (get_next_line(0, &line, 0) != 1)
	{
		free(asset->map);
		return (1);
	}
	free(line);
	return (0);
}

/*static int	check_line(t_asset *asset, char **line, int i)
{
	if (ft_strlen(*line) != asset->y_max + 5)
	{
		while (i > 0)
			free(asset->map[i--]);
		free(*line);
		return (1);
	}
	return (0);
}*/

int		get_map(t_asset *asset)
{
	int		i;
	char	*line;
	int		res;

	i = 0;
	res = 0;
	while (i <= asset->y_max - 1)
	{
		if ((res = get_next_line(0, &line, 0)) != 1)
		{
			if (res == 0 && line)
				free(line);
			while (i > 0)
				free(asset->map[--i]);
			asset->map = NULL;
			return (1);
		}
		//if (check_line(asset, &line, i) == 1)
		//	return (1);
		asset->map[i++] = ft_strsub(line, 4, asset->x_max);
		free(line);
		
	}
	asset->map[i] = NULL;
	return (0);
}
