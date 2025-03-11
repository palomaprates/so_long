#include "so_long.h"

char	*touch_element(int player_x, int player_y, char **map)
{
	int	lines;
	int	len;

	lines = ((player_y + PLAYER_MARGIN)) / SQUARE_SIZE;
	len = (player_x + PLAYER_MARGIN) / SQUARE_SIZE;
	return (&map[lines][len]);
}
