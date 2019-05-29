/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:43:08 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 15:08:35 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile, char c)
{
	int temp;

	if (pile->size > 1)
	{
		temp = pile->tab[0];
		pile->tab[0] = pile->tab[1];
		pile->tab[1] = temp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

int		push(t_pile *pile_in, t_pile *pile_out, char c)
{
	int		*tab_new;
	size_t	size_in;
	size_t	size_out;

	size_in = pile_in->size;
	size_out = pile_out->size;
	if (pile_out->size > 0)
	{
		if (!(tab_new = sp_tabsub(pile_in->tab, 1, size_in + 1)))
			return (0);
		tab_new[0] = pile_out->tab[0];
		ft_tabdel(&pile_in->tab);
		pile_in->tab = tab_new;
		pile_in->size = size_in + 1;
		pile_out->tab = ft_memcpy(pile_out->tab,
			pile_out->tab + 1, 4 * (size_out - 1));
		pile_out->size = size_out - 1;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	return (1);
}

void	rotate(t_pile *pile, char c)
{
	int		*addr;
	int		temp;
	size_t	size;
	size_t	i;

	size = pile->size;
	if (size > 1)
	{
		i = 0;
		addr = pile->tab;
		temp = addr[0];
		while (i < size - 1)
		{
			addr[i] = addr[i + 1];
			i++;
		}
		addr[size - 1] = temp;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rev_rotate(t_pile *pile, char c)
{
	int		*addr;
	int		temp;
	size_t	size;

	size = pile->size;
	if (size > 1)
	{
		addr = pile->tab;
		temp = addr[size - 1];
		size--;
		while (size > 0)
		{
			addr[size] = addr[size - 1];
			size--;
		}
		addr[0] = temp;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
