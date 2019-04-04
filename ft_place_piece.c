/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:11:53 by plaurent          #+#    #+#             */
/*   Updated: 2019/04/04 14:06:46 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		st_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (--i);
}

static int	*ft_pos_piece(char **piece, int *pos)
{
	int		k;
	int		l;

	k = pos[0];
	l = pos[1];
	while (piece[k][l] && piece[k][l] != '*')
	{
		l++;
		if (!piece[k][l])
		{
			k++;
			l = 0;
		}
		if (!piece[k])
			return (0);
	}
	if (piece[k][l] && piece[k][l] == '*')
	{
		pos[0] = k;
		pos[1] = l;
		return (pos);
	}
	return (0);
}

static int	ft_check(t_asset asset, int y, int x)
{
	int		k;
	int		l;
	int		i;

	k = 0;
	l = 0;
	i = 0;
	while (asset.piece[k] && asset.piece[k][l] != '\0')
	{
		if (asset.piece[k][l] == '*' && (asset.map[y][x] == asset.player || asset.map[y][x] == (asset.player + 32)))
			i++;
		if (asset.piece[k][l] == '*' && asset.map[y][x] == '\0')
			return(2);
		if (asset.piece[k] && asset.piece[k][l + 1])
		{
			l++;
			x++;
		}
		else
		{
			k++;
			y++;
			x = x - l;
			l = 0;
		}
	}
	return (i);
}

static int	ft_test2(t_asset asset, int y, int x)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (asset.piece[k] && asset.piece[k][l] != '\0')
	{
		if ((asset.piece[k][l] == '.') || ((asset.piece[k][l] == '*')
					&& (asset.map[y] && asset.map[y][x] != '\0'
						&& asset.map[y][x] != asset.adv && asset.map[y][x] !=
						(asset.adv + 32) && (asset.map[y][x] == '.'
							|| asset.map[y][x] == asset.player
							|| asset.map[y][x] == (asset.player + 32)))))
		{
			if (asset.piece[k] && asset.piece[k][l++ + 1])
				x++;
			else
			{
				k++;
				y++;
				x = x - l + 1;
				l = 0;
			}
		}
		else if (asset.piece[k][l] == '*')
			break ;
	}
	return (k);
}

static int	*ft_test(t_asset asset, int y, int x)
{
	int		k;
	int		n1;
	int		n2;

	//ft_putnbr(y);
	//ft_putnbr(x);
	//write(1, "|", 1);
	if (x >= 0 && y >= 0)
	{
		k = ft_test2(asset, y, x);
		if (!asset.piece[k] && ft_check(asset, y, x) <= 1)
		{
			n1 = ((asset.last_p[0] - y) * (asset.last_p[0] - y)) + ((asset.last_p[1] - x) * (asset.last_p[1] - x));
			if (asset.res[0] != 0 && asset.res[1] != 0)
			{
				n2 = ((asset.last_p[0] - asset.res[0]) * (asset.last_p[0] - asset.res[0])) + ((asset.last_p[1] - asset.res[1]) * (asset.last_p[1] - asset.res[1]));
				if (n1 < n2)
				{
					asset.res[0] = y;
					asset.res[1] = x;
				}
				//ft_putnbr(n1);
				//ft_putnbr(n2);
			}
			else
			{
				//write(1, "first", 5);
				asset.res = malloc(sizeof(int) * 2);
				asset.res[0] = y;
				asset.res[1] = x;
			}
			//ft_putnbr(asset.res[0]);
			//ft_putnbr(asset.res[1]);
			//write(1, "/", 1);
		}
	}
	return (asset.res);
}

static t_asset	ft_check_place(t_asset asset, int i, int j)
{
	int		y;
	int		x;
	int		*coord;
	int		*res;

	coord = (int *)malloc(sizeof(int) * 3);
	coord[0] = 0;
	coord[1] = 0;
	while ((coord = ft_pos_piece(asset.piece, coord)))
	{
		//write(1, "test3.3", 7);
		y = i - coord[0];
		x = j - coord[1];
		asset.res = ft_test(asset, y, x);
		if (asset.piece[coord[0]][coord[1]] && asset.piece[coord[0]][coord[1] + 1])
			coord[1] = coord[1] + 1;
		else if (asset.piece[coord[0]] && asset.piece[coord[0] + 1])
		{
			coord[1] = 0;
			coord[0] = coord[0] + 1;
		}
		else
			return (asset);
	}
	return (asset);
}

t_asset			ft_pos_map(t_asset asset, int i, int j)
{
	if (asset.map[i] && asset.map[i][j] != asset.player)
	{
		//write(1, "test3.1", 7);
		if (asset.map[i][j] == '.' || asset.map[i][j] == asset.adv
				|| asset.map[i][j] == (asset.adv + 32))
			return (ft_pos_map(asset, i, j = j + 1));
		else
			return (ft_pos_map(asset, i = i + 1, 4));
	}
	else if (asset.map[i])
	{
		//write(1, "test3.2", 7);
		asset = ft_check_place(asset, i, j);
		return (ft_pos_map(asset, i, j = j + 1));
	}
	else
		return (asset);
}

/*int		main()
{
	char	**map;
	char	**piece;
	int i = 0;

	map = (char **)malloc(sizeof(char *) * 5);
	piece = (char **)malloc(sizeof(char *) * 3);

	while (i < 4)
		map[i++] = ft_strnew(4);
	i = 0;
	while (i < 2)
		piece[i++] = ft_strnew(2);
	
	map[0] = "X...";
	map[1] = ".X..";
	map[2] = "....";
	map[3] = "...X";
	map[4] = NULL;

	piece[0] = "*.";
	piece[1] = "*.";
	piece[2] = NULL;

	write(1, "debut", 5);

	ft_pos_map(map, piece, 0, 0);
	return (0);
}*/
