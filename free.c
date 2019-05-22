#include "ft_filler.h"

void	free_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i] != NULL)
		free((*tab)[i++]);
	free(*tab);
}

void		free_all(t_asset *asset)
{
	int		i;

	i = 0;
	while (i < asset->y_max)
		free(asset->map[i++]);
	free(asset->map);
	asset->map = NULL;
	i = 0;
	while (i < asset->y_max)
		free(asset->heat_map[i++]);
	free(asset->heat_map);
	asset->heat_map = NULL;
	i = 0;
	while (i < asset->y_max)
		free(asset->piece[i++]);
	free(asset->piece);
	asset->piece = NULL;
}
