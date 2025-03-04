#include "../so_long.h"

void	print_exit(t_data *param)
{
	static int	i;
	if (!number_of_elements(param->map, COINS))
	{
		if (!i) param->exit.width = -30;
		param->exit.height = 2;
		while (i < 4)
		{
			param->exit.x = 10 - i * 2;
			param->exit.y = 10;
			param->exit.width += 30;
			if (param->exit.width >= 130)
			param->exit.width = 1;
			print_element(&param->canva, param->map, EXIT, &param->background);
			print_avatar(&param->canva, param->exit);
			print_avatar(&param->canva, param->player);
			mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
			usleep(150000);
			i++;
		}
		print_avatar(&param->canva, param->exit);
		mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
	}
}
