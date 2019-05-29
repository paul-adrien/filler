/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerack_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:33:13 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:20:48 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rerack_2(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->tab[1] > pile_b->tab[0])
	{
		if (pile_a->tab[0] > pile_a->tab[1])
			double_swap(pile_a, pile_b, 1);
		else
			swap(pile_b, 'b');
	}
	else
		push(pile_a, pile_b, 'a');
}

static void	rerack_3(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->tab[2] == max_get(pile_b, 3))
		rev_rotate(pile_b, 'b');
	else if (pile_b->tab[1] > pile_b->tab[0] && pile_b->tab[0] > pile_b->tab[2])
	{
		if (pile_a->tab[0] > pile_a->tab[1])
			double_swap(pile_a, pile_b, 1);
		else
			swap(pile_b, 'b');
	}
	else if (pile_b->tab[0] != max_get(pile_b, 3))
		rotate(pile_b, 'b');
	push(pile_a, pile_b, 'a');
}

static void	rerack_4(t_pile *pile_a, t_pile *pile_b)
{
	int		local_max;

	local_max = max_get(pile_b, 4);
	if (pile_b->tab[1] == local_max)
		rotate(pile_b, 'b');
	else if (pile_b->tab[2] == local_max)
	{
		rotate(pile_b, 'b');
		rotate(pile_b, 'b');
	}
	else if (pile_b->tab[3] == local_max)
		rev_rotate(pile_b, 'b');
	push(pile_a, pile_b, 'a');
}

int			rerack_cases(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->size == 1)
	{
		push(pile_a, pile_b, 'a');
		return (1);
	}
	else if (pile_b->size == 2)
		rerack_2(pile_a, pile_b);
	else if (pile_b->size == 3)
		rerack_3(pile_a, pile_b);
	else if (pile_b->size == 4)
		rerack_4(pile_a, pile_b);
	return (0);
}
