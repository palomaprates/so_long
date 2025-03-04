#include "so_long.h"

char	*touch_element(int player_x, int player_y, char **map)
{
	int	lines;
	int	len;

	lines = ((player_y + PLAYER_MARGIN)) / PLAYER_VELOCITY;
	len = (player_x + PLAYER_MARGIN) / PLAYER_VELOCITY;
	return (&map[lines][len]);
}
