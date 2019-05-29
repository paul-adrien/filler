/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:27:23 by eviana            #+#    #+#             */
/*   Updated: 2019/04/16 17:29:08 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	answer_print(t_pile *pile_a, t_pile *pile_b, t_pile *pile_perfect)
{
	if (pile_b->size == 0)
	{
		if (sp_is_increasing(pile_a->tab, pile_a->size) || pile_a->size == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else
		ft_putstr("KO\n");
	del_all(pile_a, pile_b, pile_perfect, NULL);
}

int			main(int argc, char **argv)
{
	char	*line;
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_pile	*pile_perfect;

	pile_a = NULL;
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
	while (get_next_line(0, &line) == 1)
	{
		if (!action_apply(action_nbr(line), pile_a, pile_b))
			put_error(pile_a, pile_b, pile_perfect, line);
		ft_strdel(&line);
	}
	answer_print(pile_a, pile_b, pile_perfect);
	ft_strdel(&line);
	return (0);
}
