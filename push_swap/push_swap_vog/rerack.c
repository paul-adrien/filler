/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:35:34 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:20:40 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rerack_opti(t_pile *pile_a, t_pile *pile_b)
{
	rev_rotate(pile_b, 'b');
	push(pile_a, pile_b, 'a');
	return (1);
}

static int	rerack_main(t_pile *pile_a, t_pile *pile_b, int median, size_t size)
{
	if (pile_b->tab[0] <= median && pile_b->size > 1)
		rotate(pile_b, 'b');
	else if (pile_b->size > 0)
	{
		push(pile_a, pile_b, 'a');
		if (size < 6 && pile_a->size > 2 && pile_a->tab[0] > pile_a->tab[1])
			swap(pile_a, 'a');
		return (1);
	}
	return (0);
}

void		rerack(t_pile *pile_a, t_pile *pile_b, size_t size)
{
	size_t	review;
	size_t	count;
	int		median;

	while (size)
	{
		count = (size == 1 ? 1 : size / 2);
		median = median_get(pile_b, size);
		review = size;
		while (review && count)
		{
			if (pile_b->size < 5)
			{
				if (rerack_cases(pile_a, pile_b))
					return ;
			}
			else if (pile_b->tab[pile_b->size - 1] == max_get(pile_b, size))
				count = count - rerack_opti(pile_a, pile_b);
			else
				count = count - rerack_main(pile_a, pile_b, median, size);
			review--;
		}
		size = (size > 1 && size % 2 ? 1 : 0) + size / 2;
	}
}
