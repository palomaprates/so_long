#include "../so_long.h"

int	close_win(t_data *param)
{
	if (param->mlx)
	{
		destroy_images(param);
		mlx_destroy_window(param->mlx, param->mlx_win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
	}
	exit(0);
	return (0);
}