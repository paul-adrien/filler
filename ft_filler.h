/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:34:26 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/30 15:23:08 by plaurent         ###   ########.fr       */
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
	int		**heat_map;
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;
	int		x_max;
	int		y_max;
	int		score;
	int		tmp_score;
	char	**map;
	//char	**lmap;
	char	**line;
	char	**piece;
	int		*last_p;
}				t_asset;

t_asset		ft_pos_map(t_asset asset, int i, int j);
t_asset		create_heat_map(t_asset asset);
#endif
