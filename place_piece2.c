/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:11:53 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/28 16:46:36 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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

static int	ft_check(char **map, char **piece, int y, int x)
{
	int		k;
	int		l;
	int		i;

	k = 0;
	l = 0;
	i = 0;
	while (piece[k] && piece[k][l] != '\0')
	{
		if (piece[k][l] == '*' && (map[y][x] == 'X' || map[y][x] == 'x'))
			i++;
		if (piece[k][l] == '*' && map[y][x] == '\0')
			return(2);
		if (piece[k] && piece[k][l + 1])
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

static int	ft_test2(char **m, char **p, int y, int x)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (p[k] && p[k][l] != '\0')
	{
		if ((p[k][l] == '.') || ((p[k][l] == '*') && (m[y] && m[y][x] != '\0'
						&& m[y][x] != 'O' && m[y][x] != 'o' && (m[y][x] == '.'
							|| m[y][x] == 'X' || m[y][x] == 'x'))))
		{
			if (p[k] && p[k][l++ + 1])
				x++;
			else
			{
				k++;
				y++;
				x = x - l + 1;
				l = 0;
			}
		}
		else if (p[k][l] == '*')
			break ;
	}
	return (k);
}

static int	ft_test(char **map, char **piece, int y, int x)
{
	int		k;

	if (x >= 0 && y >= 0)
	{
		k = ft_test2(map, piece, y, x);
		if (!piece[k] && ft_check(map, piece, y, x) <= 1)
			ft_stock(y, x, 0)
	}
	return (0);
}

static int	ft_check_place(char **map, char **piece, int i, int j)
{
	int		y;
	int		x;
	int		*coord;

	coord = (int *)malloc(sizeof(int) * 3);
	coord[0] = 0;
	coord[1] = 0;
	while ((coord = ft_pos_piece(piece, coord)))
	{
		y = i - coord[0];
		x = j - coord[1];
		if (ft_test(map, piece, y, x))
			return (1);
		if (piece[coord[0]][coord[1]] && piece[coord[0]][coord[1] + 1])
			coord[1] = coord[1] + 1;
		else if (piece[coord[0]] && piece[coord[0] + 1])
		{
			coord[1] = 0;
			coord[0] = coord[0] + 1;
		}
		else
			return (0);
	}
	return (0);
}

int			ft_pos_map(char **map, char **piece, int i, int j)
{
	if (map[i][j] != 'X')
	{
		if (!map[i])
			return (0);
		else if (map[i][j] == '.' || map[i][j] == 'O' || map[i][j] == 'o')
			return (ft_pos_map(map, piece, i, j = j + 1));
		else
			return (ft_pos_map(map, piece, i = i + 1, 4));
	}
	else
	{
		if (!(ft_check_place(map, piece, i, j)))
			return (ft_pos_map(map, piece, i, j = j + 1));
		else
			return (1);
	}
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










