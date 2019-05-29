/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:25:46 by eviana            #+#    #+#             */
/*   Updated: 2019/04/11 19:42:33 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_pile *pile_a, t_pile *pile_b, int i)
{
	swap(pile_a, 0);
	swap(pile_b, 0);
	if (i)
		write(1, "ss\n", 3);
}

void	double_rotate(t_pile *pile_a, t_pile *pile_b, int i)
{
	rotate(pile_a, 0);
	rotate(pile_b, 0);
	if (i)
		write(1, "rr\n", 3);
}

void	mult_rev_rotate(t_pile *pile, char c, int i)
{
	while (i)
	{
		rev_rotate(pile, c);
		i--;
	}
}

void	double_rev_rotate(t_pile *pile_a, t_pile *pile_b, int i)
{
	rev_rotate(pile_a, 0);
	rev_rotate(pile_b, 0);
	if (i)
		write(1, "rrr\n", 4);
}
