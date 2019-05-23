#include "filler.h"

static char	**test_line(char **tab)
{
	if (ft_strcmp(tab[0], "$$$") != 0 || ft_strcmp(tab[1], "exec") != 0
		|| ft_strcmp(tab[3], ":") != 0
		|| ft_strcmp(tab[4], "[players/plaurent.filler]") != 0)
		tab[2] = "er";
	return (tab);
}

int		get_player(t_asset *asset)
{
	if (get_next_line(0, &asset->line, 0) != 1)
		return (1);
	if (!(asset->tab = ft_strsplit(asset->line, ' ')))
	{
		free(asset->line);
		return (1);
	}
	ft_strdel(&asset->line);
	asset->tab = test_line(asset->tab);
	if (ft_strcmp(asset->tab[2], "p2") == 0)
	{
		asset->player = 'X';
		asset->adv = 'O';
	}
	else if (ft_strcmp(asset->tab[2], "p1") != 0)
	{
		free_tab(&asset->tab);
		return (1);
	}
	free_tab(&asset->tab);
	return (0);
}
