/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:44:33 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 14:39:15 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_ra_rra(t_pile *pile, int median, size_t size)
{
	size_t review;

	review = 0;
	while (review < size)
	{
		if (pile->tab[review] <= median)
			return (0);
		review++;
	}
	return (1);
}

static int	check_sa(t_pile *pile_a, t_pile *pile_b, int i, size_t size)
{
	if (size != 2)
		return (0);
	size = pile_a->size;
	if (pile_b->size < 6)
	{
		if (pile_a->tab[1] > max_get(pile_b, pile_b->size)
				&& pile_a->tab[0] > pile_a->tab[1])
		{
			while (i)
			{
				if (pile_a->tab[1] < pile_a->tab[size - i])
					return (0);
				i--;
			}
			if (pile_b->size > 1 && pile_b->tab[1] > pile_b->tab[0])
				double_swap(pile_a, pile_b, 1);
			else
				swap(pile_a, 'a');
			return (1);
		}
	}
	return (0);
}

static void	ms_opti(t_pile *pile_a, t_pile *pile_b, int *i)
{
	if (*i == 2
			&& pile_a->tab[pile_a->size - 1] < pile_a->tab[pile_a->size - 2])
	{
		rev_rotate(pile_a, 'a');
		rev_rotate(pile_a, 'a');
		*i = *i - 2;
		if (pile_b->tab[1] > pile_b->tab[0])
			double_swap(pile_a, pile_b, 1);
		else
			swap(pile_a, 'a');
	}
}

size_t		median_split
	(t_pile *pile_a, t_pile *pile_b, int median, size_t size)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (size)
	{
		if (pile_a->tab[0] <= median)
		{
			push(pile_b, pile_a, 'b');
			res++;
		}
		else
		{
			if (check_sa(pile_a, pile_b, i, size)
					|| check_ra_rra(pile_a, median, size))
				break ;
			rotate(pile_a, 'a');
			i++;
		}
		size--;
	}
	ms_opti(pile_a, pile_b, &i);
	mult_rev_rotate(pile_a, 'a', i);
	return (res);
}
