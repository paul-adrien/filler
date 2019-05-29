/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:10:43 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 14:12:01 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		action_apply(short n, t_pile *pile_a, t_pile *pile_b)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		swap(pile_a, 0);
	else if (n == 2)
		swap(pile_b, 0);
	else if (n == 3)
		double_swap(pile_a, pile_b, 0);
	else if (n == 4)
		push(pile_a, pile_b, 0);
	else if (n == 5)
		push(pile_b, pile_a, 0);
	else if (n == 6)
		rotate(pile_a, 0);
	else if (n == 7)
		rotate(pile_b, 0);
	else if (n == 8)
		double_rotate(pile_a, pile_b, 0);
	else if (n == 9)
		rev_rotate(pile_a, 0);
	else if (n == 10)
		rev_rotate(pile_b, 0);
	else if (n == 11)
		double_rev_rotate(pile_a, pile_b, 0);
	return (1);
}

int		action_nbr(char *line)
{
	short n;

	n = 0;
	n = (!n && ft_strequ(line, "sa") ? 1 : n);
	n = (!n && ft_strequ(line, "sb") ? 2 : n);
	n = (!n && ft_strequ(line, "ss") ? 3 : n);
	n = (!n && ft_strequ(line, "pa") ? 4 : n);
	n = (!n && ft_strequ(line, "pb") ? 5 : n);
	n = (!n && ft_strequ(line, "ra") ? 6 : n);
	n = (!n && ft_strequ(line, "rb") ? 7 : n);
	n = (!n && ft_strequ(line, "rr") ? 8 : n);
	n = (!n && ft_strequ(line, "rra") ? 9 : n);
	n = (!n && ft_strequ(line, "rrb") ? 10 : n);
	n = (!n && ft_strequ(line, "rrr") ? 11 : n);
	return (n);
}
