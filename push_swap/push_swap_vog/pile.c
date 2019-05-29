/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:38:18 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:22:22 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			pile_print(t_pile *pile)
{
	int size;
	int *addr;

	size = pile->size;
	addr = pile->tab;
	while (size)
	{
		ft_putnbr(*addr);
		ft_putchar('|');
		addr++;
		size--;
	}
	ft_putchar('\n');
}

static int		check_allint(char **nbrs)
{
	int		i;
	long	nbr;

	i = 0;
	while (nbrs[i])
		i++;
	while (i)
	{
		if (ft_strlen(nbrs[i - 1]) > 11)
			return (0);
		nbr = ft_atol(nbrs[i - 1]);
		if (-2147483648 > nbr || nbr > 2147483647)
			return (0);
		i--;
	}
	return (1);
}

static size_t	count_nbrs(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	size;
	char	**nbrs;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		if (!(nbrs = ft_split_whitespaces(argv[i]))
				|| !check_lone_sign(nbrs))
			return (0);
		if (!check_allint(nbrs))
		{
			ft_strtabdel(nbrs);
			return (0);
		}
		while (nbrs[j])
			j++;
		ft_strtabdel(nbrs);
		size = size + j;
		i++;
	}
	return (size);
}

static int		pile_tab_set(t_pile *pile, int argc, char **argv)
{
	int		i;
	int		j;
	int		*addr;
	char	**nbrs;

	addr = pile->tab;
	if (argv)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			if (!(nbrs = ft_split_whitespaces(argv[i])))
				return (0);
			while (nbrs[j])
			{
				*addr = ft_atoi(nbrs[j]);
				addr++;
				j++;
			}
			ft_strtabdel(nbrs);
			i++;
		}
	}
	return (1);
}

t_pile			*pile_get(int argc, char **argv)
{
	t_pile	*pile;
	size_t	size;

	if (!argv)
		size = 0;
	else if (!(size = count_nbrs(argc, argv)))
		return (NULL);
	if (!(pile = (t_pile*)malloc(sizeof(t_pile) * 1)))
		return (NULL);
	if (!(pile->tab = (int*)malloc(sizeof(int) * size)))
	{
		free(pile);
		return (NULL);
	}
	pile->size = size;
	if (!pile_tab_set(pile, argc, argv))
	{
		pile_del(pile);
		return (NULL);
	}
	return (pile);
}
