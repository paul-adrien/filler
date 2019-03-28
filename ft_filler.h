/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:34:26 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/28 14:51:24 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_pos
{
	int		*x_max;
	int		*x_min;
	int		*y_max;
	int		*y_min;
}				t_pos

int		ft_pos_map(char **map, char **piece, int i, int j);
#endif
