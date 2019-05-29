/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:20:22 by eviana            #+#    #+#             */
/*   Updated: 2019/04/16 17:17:58 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_pile	*pile_perfect;
	t_size	*all_chunks;

	pile_a = NULL;
	pile_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_alldigit(argc, argv) || !(pile_a = pile_get(argc, argv)))
		put_error(NULL, NULL, NULL, NULL);
	if (!(pile_b = pile_get(1, NULL)))
		put_error(pile_a, NULL, NULL, NULL);
	if (!(pile_perfect = pile_quick_sort(pile_a)))
		put_error(pile_a, pile_b, NULL, NULL);
	if (!sp_is_increasing(pile_perfect->tab, pile_perfect->size))
		put_error(pile_a, pile_b, pile_perfect, NULL);
	if (!(all_chunks = all_chunks_get(pile_perfect->size)))
		put_error(pile_a, pile_b, pile_perfect, NULL);
	if (pile_a->size < 6)
		easy_sort(pile_a, pile_b);
	else if (!sp_is_increasing(pile_a->tab, pile_a->size))
		pile_sort(pile_a, pile_b, pile_perfect, all_chunks);
	del_all(pile_a, pile_b, pile_perfect, all_chunks);
	return (0);
}
