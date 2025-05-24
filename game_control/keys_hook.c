#include "../so_long.h"


int	keys_hook(int key_code, t_data *param)
{
	static int	i;
	movements(key_code, param);
	if (key_code == 119 || key_code == 115 || key_code == 97 || key_code == 100)
		ft_printf("%d moves\n", i++);
	game_images(param);
	if (key_code == 65307)
		cleanup_and_exit(param);
	return (0);
}
