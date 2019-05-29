/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:18:49 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:05:49 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int			check_lone_sign(char **nbrs)
{
	int i;

	i = 0;
	while (nbrs[i])
	{
		if (ft_strlen(nbrs[i]) == 1 && is_sign(nbrs[i][0]))
		{
			ft_strtabdel(nbrs);
			return (0);
		}
		i++;
	}
	return (1);
}

int			check_alldigit(int argc, char **argv)
{
	size_t size;

	while (argc > 1)
	{
		size = ft_strlen(argv[argc - 1]);
		while (size)
		{
			if (!ft_isdigit((int)argv[argc - 1][size - 1])
					&& !((size == 1 && is_sign(argv[argc - 1][size - 1]))
						|| (size > 1 && is_sign(argv[argc - 1][size - 1])
							&& is_space(argv[argc - 1][size - 2])))
								&& !is_space(argv[argc - 1][size - 1]))
				return (0);
			size--;
		}
		argc--;
	}
	return (1);
}
