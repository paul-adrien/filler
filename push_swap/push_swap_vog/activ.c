/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:18:49 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 14:28:24 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_resize
	(t_pile *pile_a, t_size *all_chunks, size_t *size, int *median)
{
	if (all_chunks->tab[all_chunks->current].activ == 1
			&& (int)*size != all_chunks->tab[all_chunks->current - 1].value / 2)
	{
		*size = all_chunks->tab[all_chunks->current - 1].value / 2;
		*median = median_get(pile_a, *size);
	}
}

void	activ_switch(t_size *all_chunks)
{
	if (all_chunks->tab[all_chunks->current].activ == 0)
		all_chunks->tab[all_chunks->current].activ = 1;
	else if (all_chunks->tab[all_chunks->current].activ == 1)
		all_chunks->tab[all_chunks->current].activ = 0;
}
