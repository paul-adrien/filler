/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:29:33 by eviana            #+#    #+#             */
/*   Updated: 2019/04/14 18:34:29 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*sp_tabsub(int *tab, unsigned int start, size_t size_new)
{
	int		*tab_new;
	size_t	i;

	i = 0;
	if (!tab || !(tab_new = (int*)malloc(sizeof(int) * size_new)))
		return (NULL);
	while (i < size_new - start)
	{
		tab_new[start + i] = tab[i];
		i++;
	}
	return (tab_new);
}

int		sp_is_increasing(int *tab, size_t size)
{
	if (size > 1)
	{
		if (tab[size - 1] <= tab[size - 2])
			return (0);
		else if (tab[size - 1] > tab[size - 2])
			while (size > 1)
			{
				if (tab[size - 1] <= tab[size - 2])
					return (0);
				size--;
			}
		return (1);
	}
	else if (size == 1)
		return (1);
	else
		return (0);
}

int		sp_is_sort(int *tab, size_t size)
{
	if (size > 0)
	{
		if (tab[size - 1] < tab[size - 2])
			while (size > 2)
			{
				if (tab[size - 1] >= tab[size - 2])
					return (0);
				size--;
			}
		else if (tab[size - 1] > tab[size - 2])
			while (size > 2)
			{
				if (tab[size - 1] <= tab[size - 2])
					return (0);
				size--;
			}
		return (1);
	}
	else
		return (0);
}
