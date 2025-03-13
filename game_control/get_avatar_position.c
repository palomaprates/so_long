#include "../so_long.h"

void	get_avatar_position(t_sprite *player, t_sprite *exit, char **map)
{
	int	lines;
	int	len;

	lines = 0;
	while(map[lines])
	{
		len = 0;
		while(map[lines][len])
		{
			if (map[lines][len] == PLAYER)
			{
				player->x = len * SQUARE_SIZE - PLAYER_MARGIN;
				player->y = lines * SQUARE_SIZE - PLAYER_MARGIN;
			}
			if (map[lines][len] == EXIT)
			{
				exit->x = len * SQUARE_SIZE;
				exit->y = lines * SQUARE_SIZE - EXIT_MARGIN;
			}
			len++;
		}
		lines++;
	}
}
