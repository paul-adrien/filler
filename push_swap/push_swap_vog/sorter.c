/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:14:25 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 18:32:45 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_cases(t_pile *pile_a, t_pile *pile_perfect, size_t *size)
{
	if (*size == 2)
	{
		if (is_next(pile_a->tab[1], pile_a->tab[0], pile_perfect))
			swap(pile_a, 'a');
		rotate(pile_a, 'a');
		rotate(pile_a, 'a');
		return (1);
	}
	if (*size == 4 && is_next(pile_a->tab[pile_a->size - 1],
			pile_a->tab[0], pile_perfect))
	{
		rotate(pile_a, 'a');
		*size = 3;
	}
	return (0);
}

static int	sort_exception(t_pile *pile_a, t_pile *pile_perfect, size_t size)
{
	if (size == 3 || (size < 7 && sp_is_increasing(pile_a->tab, size))
		|| ((size == 5 || size == 6) && is_next(pile_a->tab[pile_a->size - 1],
			pile_a->tab[0], pile_perfect)
				&& is_next(pile_a->tab[0], pile_a->tab[1], pile_perfect)
					&& is_next(pile_a->tab[1], pile_a->tab[2], pile_perfect)))
		return (1);
	return (0);
}

static int	chunks_sort
	(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect, t_size *all_chunks)
{
	int	review;

	review = all_chunks->size;
	while (review > 1 && all_chunks->current < all_chunks->size)
	{
		all_chunks->current = review - 1;
		if (all_chunks->tab[all_chunks->current].value != 2)
		{
			if (pile_sort(pile_a, pile_b, pile_perfect, all_chunks))
			{
				free(all_chunks->tab);
				free(all_chunks);
				return (1);
			}
		}
		review--;
	}
	free(all_chunks->tab);
	free(all_chunks);
	return (0);
}

int			pile_sort
	(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect, t_size *all_chunks)
{
	size_t	size;
	size_t	to_order;
	int		median;

	size = all_chunks->tab[all_chunks->current].value;
	if ((size > 2 && size % 2 ? 1 : 0) + size / 2)
	{
		median = median_get(pile_a, size);
		if (size == pile_perfect->size)
			init_sort(pile_a, pile_b, median, size);
		else
		{
			sort_resize(pile_a, all_chunks, &size, &median);
			if (sort_cases(pile_a, pile_perfect, &size))
				return (0);
			if (!sort_exception(pile_a, pile_perfect, size)
					&& (to_order = median_split(pile_a, pile_b, median, size)))
				rerack(pile_a, pile_b, to_order);
		}
		activ_switch(all_chunks);
		all_chunks = all_chunks_get(size);
		if (chunks_sort(pile_a, pile_b, pile_perfect, all_chunks))
			return (1);
	}
	return (reorder(pile_a, pile_b, pile_perfect, size));
}
