/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:23:11 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 16:02:01 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reorder_cases1(t_pile *pile_a, t_pile *pile_perfect)
{
	if ((pile_a->tab[0] == pile_perfect->tab[0]
				&& !sp_is_sort(pile_a->tab, pile_a->size))
					|| is_next(pile_a->tab[pile_a->size - 1],
						pile_a->tab[0], pile_perfect))
	{
		rotate(pile_a, 'a');
		return (1);
	}
	else if ((is_next(pile_a->tab[1], pile_a->tab[0], pile_perfect)
				&& !is_next(pile_a->tab[2], pile_a->tab[1], pile_perfect))
					|| is_next(pile_a->tab[pile_a->size - 1],
						pile_a->tab[1], pile_perfect))
	{
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
		return (1);
	}
	return (0);
}

static int	reorder_cases2(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect)
{
	if (is_next(pile_a->tab[0], pile_a->tab[1], pile_perfect)
			&& is_next(pile_a->tab[2], pile_a->tab[0], pile_perfect))
	{
		push(pile_b, pile_a, 'b');
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
		push(pile_a, pile_b, 'a');
		rotate(pile_a, 'a');
		rotate(pile_a, 'a');
		return (1);
	}
	else if (is_next(pile_a->tab[1], pile_a->tab[0], pile_perfect)
			&& is_next(pile_a->tab[2], pile_a->tab[1], pile_perfect))
	{
		push(pile_b, pile_a, 'b');
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
		rotate(pile_a, 'a');
		push(pile_a, pile_b, 'a');
		rotate(pile_a, 'a');
		return (1);
	}
	return (0);
}

static int	reorder_cases3(t_pile *pile_a, t_pile *pile_perfect, int i)
{
	if (i == 0 && is_next(pile_a->tab[2], pile_a->tab[0], pile_perfect)
			&& is_next(pile_a->tab[1], pile_a->tab[2], pile_perfect))
	{
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
		rotate(pile_a, 'a');
		return (1);
	}
	else if (pile_a->tab[0] == pile_perfect->tab[0]
			&& pile_a->size == pile_perfect->size
			&& (pile_a->tab[pile_a->size - 1]
				== pile_perfect->tab[pile_perfect->size - 1])
			&& sp_is_sort(pile_a->tab, pile_a->size))
		return (2);
	return (0);
}

static int	reorder_trio(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect)
{
	int i;

	i = 0;
	if (pile_a->size >= 3)
	{
		while (i < 3)
		{
			if (reorder_cases1(pile_a, pile_perfect))
				i++;
			else if (i == 0 && reorder_cases2(pile_a, pile_b, pile_perfect))
				i = i + 3;
			else if (reorder_cases3(pile_a, pile_perfect, i) == 1)
				i = i + 3;
			else
				return (1);
		}
	}
	return (0);
}

int			reorder
	(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect, size_t size)
{
	if (size == 4
			&& is_next(pile_a->tab[pile_a->size - 1],
				pile_a->tab[0], pile_perfect))
		rotate(pile_a, 'a');
	else if (size == 1)
	{
		if (reorder_trio(pile_a, pile_b, pile_perfect))
			return (1);
	}
	return (0);
}
