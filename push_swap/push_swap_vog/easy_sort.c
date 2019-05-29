/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:20:22 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:08:43 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	easy_case_5(t_pile *pile_a, t_pile *pile_b, int median, size_t size)
{
	int		i;

	i = 0;
	while (i != (size % 2 ? 1 : 0) + size / 2 && !(pile_a->size == size
			&& sp_is_increasing(pile_a->tab, size)))
	{
		if (pile_a->tab[0] > median)
			rotate(pile_a, 'a');
		else
		{
			push(pile_b, pile_a, 'b');
			i++;
		}
	}
	while (!(pile_a->size == size && sp_is_increasing(pile_a->tab, size)))
	{
		if (pile_a->tab[0] > pile_a->tab[1])
			swap(pile_a, 'a');
		else if (pile_b->size == 3 && pile_b->tab[2] == max_get(pile_b, 3))
			rev_rotate(pile_b, 'b');
		else
			push(pile_a, pile_b, 'a');
		i++;
	}
}

static void	easy_case_3(t_pile *pile_a)
{
	int max;

	max = max_get(pile_a, pile_a->size);
	if (pile_a->tab[pile_a->size - 1] == max)
	{
		if (pile_a->tab[0] > pile_a->tab[1])
			swap(pile_a, 'a');
	}
	else if (pile_a->tab[0] == max)
	{
		rotate(pile_a, 'a');
		if (pile_a->tab[0] > pile_a->tab[1])
			swap(pile_a, 'a');
	}
	else
	{
		rev_rotate(pile_a, 'a');
		if (pile_a->tab[0] > pile_a->tab[1])
			swap(pile_a, 'a');
	}
}

void		easy_sort(t_pile *pile_a, t_pile *pile_b)
{
	int		median;
	size_t	size;

	if (pile_a->size == 1)
		return ;
	else if (pile_a->size < 4)
		easy_case_3(pile_a);
	else
	{
		size = pile_a->size;
		median = median_get(pile_a, size);
		easy_case_5(pile_a, pile_b, median, size);
	}
}
