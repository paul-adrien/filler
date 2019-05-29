/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:29:44 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 18:32:34 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_next(int previous, int next, t_pile *pile_perfect)
{
	size_t i;
	size_t size;

	i = 0;
	size = pile_perfect->size;
	while (pile_perfect->tab[i] != previous && i < size)
		i++;
	if (i < size - 1 && pile_perfect->tab[i + 1] == next)
		return (1);
	return (0);
}

int		max_get(t_pile *pile, size_t size)
{
	int		max;
	size_t	review;

	max = pile->tab[0];
	review = 1;
	while (review < size)
	{
		if (pile->tab[review] > max)
			max = pile->tab[review];
		review++;
	}
	return (max);
}

int		min_get(t_pile *pile, size_t size)
{
	int		min;
	size_t	review;

	min = pile->tab[0];
	review = 1;
	while (review < size)
	{
		if (pile->tab[review] < min)
			min = pile->tab[review];
		review++;
	}
	return (min);
}

int		medium_get(t_pile *pile, size_t size)
{
	int		medium;
	int		sum;
	size_t	review;

	review = 0;
	sum = 0;
	while (review < size)
	{
		sum = sum + pile->tab[review];
		review++;
	}
	medium = (review != 0 ? sum / review : 0);
	return (medium);
}

int		median_get(t_pile *pile, size_t size)
{
	int		median;
	int		*tab_copy;

	tab_copy = sp_tabsub(pile->tab, 0, size);
	quick_sort(tab_copy, size);
	median = tab_copy[size / 2 - (size > 1 && size % 2 == 0 ? 1 : 0)];
	free(tab_copy);
	return (median);
}
