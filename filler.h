/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:34:26 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/23 14:19:43 by plaurent         ###   ########.fr       */
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
	int		x_pmax;
	int		y_pmax;
	int		score;
	int		tmp_score;
	//char	**lmap;
	char	**map;
	char	**tab;
	char	*line;
	char	**piece;
	int		error;
	//int	*last_p;
	//int	*last_p2;
}				t_asset;

t_asset		new_place(t_asset asset, int y, int x);
void		free_all(t_asset *asset);
int		get_piece(t_asset *asset);
int		piece_info(t_asset *asset);
void		free_tab(char ***tab);
int		map_info(t_asset *asset);
int		get_map(t_asset *asset);
int		get_player(t_asset *asset);
t_asset		find_place(t_asset asset, int i, int j);
int		create_heat_map(t_asset *asset);
t_asset		init_heat_map(t_asset asset);
#endif
