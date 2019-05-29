/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:54:23 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:19:31 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *tab, int size)
{
	int wall;
	int current;
	int pivot;

	if (size < 2)
		return ;
	pivot = tab[size - 1];
	wall = 0;
	current = 0;
	while (current < size)
	{
		if (tab[current] <= pivot)
		{
			if (wall != current)
				ft_swap(&tab[current], &tab[wall]);
			wall++;
		}
		current++;
	}
	quick_sort(tab, wall - 1);
	quick_sort(tab + wall - 1, size - wall + 1);
}

t_pile	*pile_quick_sort(t_pile *pile_a)
{
	t_pile	*pile_perfect;

	if (!(pile_perfect = pile_get(1, NULL)))
		return (NULL);
	free(pile_perfect->tab);
	if (!(pile_perfect->tab = sp_tabsub(pile_a->tab, 0, pile_a->size)))
		return (NULL);
	pile_perfect->size = pile_a->size;
	quick_sort(pile_perfect->tab, pile_perfect->size);
	return (pile_perfect);
}
