#include "../so_long.h"

int	keys_hook(int key_code, t_data *param)
{
	movements(key_code, param);
	game_images(param);
	if (key_code == 65307)
		close_win(param);
	return (0);
}
