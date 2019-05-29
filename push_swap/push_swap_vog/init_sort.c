/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:14:13 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:08:59 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_split(t_pile *pile_a, t_pile *pile_b, int median, size_t size)
{
	while (size)
	{
		if (pile_a->tab[0] <= median)
			push(pile_b, pile_a, 'b');
		else
			rotate(pile_a, 'a');
		size--;
	}
}

void		init_sort(t_pile *pile_a, t_pile *pile_b, int median, size_t size)
{
	init_split(pile_a, pile_b, median, size);
	rerack(pile_a, pile_b, (size > 1 && size % 2 ? 1 : 0) + size / 2);
}
