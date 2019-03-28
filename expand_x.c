/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:28:26 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/28 11:58:01 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.c"

static int	*ft_choice_coord(char **map, int *i, int *j, char p)
{

}

int		ft_expand_x(char **map, char **piece, char p, int dir)
{
	int		i;
	int		j;
	int		*k;

	k = ft_choice_coord(map, &i, &j, p);
	if (map[i][j] != p)
	{
		if (!map[i])
			return (0);
		else if (map[i][j] == '.' || map[i][j] == 'O' || map[i][j] == 'o')
			return (ft_pos_map(map, piece, i, j = j + k[0]));
		else
			return (ft_pos_map(map, piece, i = i + k[1], k[2]));
	}
	else
	{
		if (!(ft_check_place(map, piece, i, j)))
			return (ft_pos_map(map, piece, i, j = j + k[0]));
		else
			return (1);
	}
}
