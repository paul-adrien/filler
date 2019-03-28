/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice_strat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:14:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/28 16:46:38 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_center(char **map, char player)
{
	int		k;
	int		y;
	int		x;
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]) / 10;
	x = (k * 10) / 2;
	y = st_tablen(map) / 2;
	while (map[i])
	{
		if (i < (y + k) && i > (y - k) && i + j < y + 1 && j < (x + k)
				&& j > (y - k))
			if (map[i][j] == 'X' || map[i][j] == 'O' || map[i][j] == 'o')
				return (0);
		if (map[i][j] && map[i][j + 1])
			j++;
		else if (map[i] && map[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (1);
}

int		ft_choice_mode(char **map, char player)
{

}

int		ft_stock(int k, int l, int m)
{
	static int	mode = 0;
	static int	y = 0;
	static int	x = 0;

	if (!mode && m)
		mode = m;
	else if ((mode == 1 && l > x) || (mode == 2 && l < x) || (mode == 3 && k < y)
			|| (mode == 4 && k > y))
	{
		y = k;
		x = l;
		return (0)
	}
	if (mode == 5)
	{
		write(1, &y, 1);
		write(1, " ", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
	return (0);
}

void	ft_envlope(char **map, char **piece, char player)
{
	ft_pos_map_touch_last_ox(map, piece, 0, 0, player)
}

void	ft_choice_strat(char **map, char **piece, char player)
{
	if (ft_center(map, player))
		ft_first_step;
	if ((mode = ft_choice_mode(map, player)))
	{
		ft_pos_map(map, piece, 0, 0, player);
		ft_stock(0, 0, 5);
	}
	ft_envlope(map, piece, player);
}
