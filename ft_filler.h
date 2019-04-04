/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:34:26 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/04 14:55:35 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_point
{
	int		y;
	int		x;
}				t_point;

typedef struct	s_asset
{
	char	player;
	char	adv;
	//t_point	size_map;
	//t_point	size_piece;
	char	**map;
	char	**lmap;
	char	**piece;
	int		*last_p;
	int		*res;
}				t_asset;

t_asset		ft_pos_map(t_asset asset, int i, int j);
#endif
