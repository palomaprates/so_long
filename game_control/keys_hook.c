#include "../so_long.h"

int	keys_hook(int key_code, t_data *param)
{
	static int	i;
	movements(key_code, param);
	printf("%d moves\n", i++);
	game_images(param);
	if (key_code == 65307)
	close_win(param);
	return (0);
}
