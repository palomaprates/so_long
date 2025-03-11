#include "../so_long.h"

void	get_avatar_position(t_sprite *player, t_sprite *exit, char **map)
{
	int	lines;
	int	len;
	int	player_position;
	lines = 0;
	while(map[lines])
	{
		len = 0;
		while(map[lines][len])
		{
			if (map[lines][len] == PLAYER)
			{
				player->x = len * PLAYER_VELOCITY + PLAYER_MARGIN;
				player->y = lines * PLAYER_VELOCITY + PLAYER_MARGIN;
			}
			if (map[lines][len] == EXIT)
			{
				exit->x = len * PLAYER_VELOCITY + PLAYER_MARGIN;
				exit->y = lines * PLAYER_VELOCITY + PLAYER_MARGIN;
				return ;
			}
			len++;
		}
		lines++;
	}
}
