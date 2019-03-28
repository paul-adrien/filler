/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:59:43 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/28 14:16:59 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.c"

/*int			*ft_pos_piece(char **tab, int *dir, int *c)
{
	int		*c;

	c = malloc(sizeof(int) * 2);
	if (dir[1] == 1)
		c[1] = ft_strlen(tab[0]);
	else
		c[1] = 0;
	if (dir[0] == 1)
		c[0] = st_tablen(tab);
	else
		coord[0] = 0;
	while (tab[c[0]][c[1]] != '*')
	{
		if (!tab[c[0]])
			return (0);
		else if (tab[c[0]][c[1]] == '.')
			c[1] = c[1] + dir[0];
		else
		{
			c[0] = c[0] + dir[1];
			c[1] = dir[2];
		}
	}
	return (c);
}*/

static int	*ft_init

int			*ft_pos_tab(char **tab, char player, int *dir, int *c)
{
	int		*c;

	c = malloc(sizeof(int) * 2);
	if (dir[1] == -1)
		c[1] = ft_strlen(tab[0]);
	else
		c[1] = 0;
	if (dir[0] == -1)
		c[0] = st_tablen(tab);
	else
		coord[0] = 0;
	while (tab[c[0]][c[1]] != player)
	{
		if (!tab[c[0]])
			return (0);
		else if (tab[c[0]][c[1]] == '.' || tab[c[0]][c[1]] == 'O'
				|| tab[c[0]][c[1]] == 'o')
			c[1] = c[1] + dir[0];
		else
		{
			c[0] = c[0] + dir[1];
			c[1] = dir[2];
		}
	}
	return (c);
}

int		ft_first_step()
{
	int		*dir;
	int		*coord;
	int		*coord2;

	dir = ft_choice_dir(map);
	coord = ft_init_coord(coord, dir, 1);
	coord2 = ft_init_coord(coord2, dir, 2);
	coord = ft_pos_tab(map, player, dir, coord);
	coord2 = ft_pos_tab(piece, player, dir, coord2);
}
