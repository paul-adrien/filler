/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:29:26 by eviana            #+#    #+#             */
/*   Updated: 2019/04/15 11:21:57 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_pile
{
	int		*tab;
	size_t	size;
}				t_pile;

typedef	struct	s_tab
{
	int		value;
	int		activ;
}				t_tab;

typedef struct	s_size
{
	t_tab	*tab;
	size_t	size;
	size_t	current;
}				t_size;

void			swap(t_pile *pile, char c);
void			double_swap(t_pile *pile_a, t_pile *pile_b, int i);
int				push(t_pile *pile_in, t_pile *pile_out, char c);
void			rotate(t_pile *pile, char c);
void			double_rotate(t_pile *pile_a, t_pile *pile_b, int i);
void			rev_rotate(t_pile *pile, char c);
void			mult_rev_rotate(t_pile *pile, char c, int i);
void			double_rev_rotate(t_pile *pile_a, t_pile *pile_b, int i);
int				min_get(t_pile *pile, size_t size);
int				max_get(t_pile *pile, size_t size);
int				medium_get(t_pile *pile, size_t size);
int				median_get(t_pile *pile, size_t size);
int				check_lone_sign(char **nbrs);
int				check_alldigit(int argc, char **argv);
void			quick_sort(int *tab, int size);
t_pile			*pile_quick_sort(t_pile *pile_a);
void			pile_del(t_pile *pile);
void			del_all(t_pile *pile_a,
				t_pile *pile_b, t_pile *pile_c, t_size *all_chunks);
void			ft_strtabdel(char **str);
void			ft_tabdel(int **tab);
int				*sp_tabsub(int *tab, unsigned int start, size_t size_new);
int				sp_is_sort(int *tab, size_t size);
int				sp_is_increasing(int *tab, size_t size);
void			pile_print(t_pile *pile);
t_pile			*pile_get(int argc, char **argv);
int				action_apply(short n, t_pile *pile_a, t_pile *pile_b);
int				action_nbr(char *line);
t_size			*all_chunks_get(size_t size);
int				rerack_cases(t_pile *pile_a, t_pile *pile_b);
void			rerack(t_pile *pile_a, t_pile *pile_b, size_t size);
int				is_next(int previous, int next, t_pile *pile_perfect);
void			sort_resize(t_pile *pile_a,
				t_size *all_chunks, size_t *size, int *median);
void			activ_switch(t_size *all_chunks);
int				reorder(t_pile *pile_a,
				t_pile *pile_b, t_pile *pile_perfect, size_t size);
size_t			median_split(t_pile *pile_a,
				t_pile *pile_b, int median, size_t size);
void			init_sort(t_pile *pile_a,
				t_pile *pile_b, int median, size_t size);
int				pile_sort(t_pile *pile_a,
				t_pile *pile_b, t_pile *perfect_pile, t_size *all_chunks);
void			easy_sort(t_pile *pile_a, t_pile *pile_b);
void			put_error(t_pile *pile_a,
				t_pile *pile_b, t_pile *pile_c, char *line);

#endif
