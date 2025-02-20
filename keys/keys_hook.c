#include "../so_long.h"

int	keys_hook(int key_code, t_data *param)
{
	if (key_code == 115)
	{
		param->avatar.y += 10;
		param->avatar.height = 98;
		if (param->avatar.width >= 32)
			param->avatar.width = 1;
	}
	if (key_code == 119)
	{
		param->avatar.y -= 10;
		param->avatar.height = 66;
		param->avatar.width += 33;
		if (param->avatar.width >= 60)
			param->avatar.width = 1;
		
	}
	if (key_code == 97)
	{
		param->avatar.x -= 10;
		param->avatar.height = 34;
		param->avatar.width += 33;
		if (param->avatar.width >= 60)
			param->avatar.width = 1;
	}
	if (key_code == 100)
	{
		param->avatar.x += 10;
		param->avatar.height = 1;
		param->avatar.width += 33;
		if (param->avatar.width >= 60)
			param->avatar.width = 1;
	}
	print_background(&param->canva);
	// print_image(&param->canva, &param->player, param->avatar.x, param->avatar.y);
	print_avatar(&param->canva, param->player, param->avatar);
	print_walls(&param->canva, param);
	// print_walls(&param->canva, param->wall, param->avatar, param->map);

	mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
	if (key_code == 65307)
		close_win(param);
	return (0);
}