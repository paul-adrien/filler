/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:07:31 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:04:16 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_chunks_fill(t_size *all_chunks, size_t size)
{
	int		i;
	size_t	size_new;

	size_new = size;
	i = 0;
	while (size_new)
	{
		all_chunks->tab[i].value = size_new;
		all_chunks->tab[i].activ = 1;
		if (size_new == 4)
		{
			if (i > 0 && all_chunks->tab[i - 1].value == 8)
				all_chunks->tab[i].value = 5;
			all_chunks->tab[i].activ = 0;
		}
		size_new = (size_new > 1 && size_new % 2 ? 1 : 0) + size_new / 2;
		i++;
	}
}

t_size		*all_chunks_get(size_t size)
{
	t_size	*all_chunks;
	size_t	size_new;
	int		i;

	i = 0;
	size_new = size;
	if (!(all_chunks = (t_size*)malloc(sizeof(t_size))))
		return (NULL);
	while (size_new)
	{
		size_new = (size_new > 1 && size_new % 2 ? 1 : 0) + size_new / 2;
		i++;
	}
	if (!(all_chunks->tab = (t_tab*)malloc(sizeof(t_tab) * i)))
	{
		free(all_chunks);
		return (NULL);
	}
	all_chunks->size = i;
	all_chunks->current = 0;
	all_chunks_fill(all_chunks, size);
	return (all_chunks);
}
