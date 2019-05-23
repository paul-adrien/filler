/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:06:23 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:16:29 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i] != NULL)
		free((*tab)[i++]);
	free(*tab);
}

void	ft_inttabdel(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	//tab = NULL;
}

void	ft_strtabdel(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void		put_error(char **map, char **piece, char *line, int **heat_map)
{
	if (map)
		ft_strtabdel(map);
	if (piece)
		ft_strtabdel(piece);
	if (line)
		ft_strdel(&line);
	if (heat_map)
		ft_inttabdel(heat_map);
	exit(1);
}

void		free_all(t_asset *asset)
{
	int		i;

	i = 0;
	while (i < asset->y_max)
		free(asset->map[i++]);
	free(asset->map);
	asset->map = NULL;
	i = 0;
	while (i < asset->y_max)
		free(asset->heat_map[i++]);
	free(asset->heat_map);
	asset->heat_map = NULL;
	i = 0;
	while (i < asset->y_max)
		free(asset->piece[i++]);
	free(asset->piece);
	asset->piece = NULL;
}
