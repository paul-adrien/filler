/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 16:05:25 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		map_info(t_asset *asset)
{
	if ((get_next_line(0, &asset->line, 0) != 1))
		exit(1);//a verifier mais sinon double free
	if (!(asset->tab = ft_strsplit(asset->line, ' ')))
		return (1);
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
	if (!(asset->map = (char **)malloc(sizeof(char *) * (asset->y_max + 1))))	
		return (1);
	if (get_next_line(0, &asset->line, 0) != 1)
	{
		free(asset->map);
		return (1);
	}
	ft_strdel(&asset->line);
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
				ft_strdel(&line);
			//while (i > 0 && asset->map[i])
				//free(asset->map[--i]);
			//asset->map = NULL; pas necessaire si fait dans put error
			return (1);
		}
		asset->map[i++] = ft_strsub(line, 4, asset->x_max);
		ft_strdel(&line);
		
	}
	asset->map[i] = NULL;
	return (0);
}
