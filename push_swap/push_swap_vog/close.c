/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:52:02 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 15:40:12 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(t_pile *pile_a, t_pile *pile_b, t_pile *pile_c, char *line)
{
	if (pile_a)
		pile_del(pile_a);
	if (pile_b)
		pile_del(pile_b);
	if (pile_c)
		pile_del(pile_c);
	if (line)
		ft_strdel(&line);
	ft_putstr_fd("Error\n", 2);
	exit(1);
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

void	ft_tabdel(int **tab)
{
	if (tab)
	{
		free(*tab);
		*tab = NULL;
	}
}

void	pile_del(t_pile *pile)
{
	free(pile->tab);
	free(pile);
}

void	del_all
	(t_pile *pile_a, t_pile *pile_b, t_pile *pile_c, t_size *all_chunks)
{
	free(pile_a->tab);
	free(pile_a);
	free(pile_b->tab);
	free(pile_b);
	free(pile_c->tab);
	free(pile_c);
	if (all_chunks)
	{
		free(all_chunks->tab);
		free(all_chunks);
	}
}
