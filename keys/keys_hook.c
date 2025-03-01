#include "../so_long.h"

int	keys_hook(int key_code, t_data *param)
{
	if (key_code == 115)
	{
		param->player.y += 10;
		param->player.height = 98;
		if (param->player.width >= 32)
			param->player.width = 1;
	}
	if (key_code == 119)
	{
		param->player.y -= 10;
		param->player.height = 66;
		param->player.width += 33;
		if (param->player.width >= 60)
			param->player.width = 1;
		
	}
	if (key_code == 97)
	{
		param->player.x -= 10;
		param->player.height = 34;
		param->player.width += 33;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
	if (key_code == 100)
	{
		param->player.x += 10;
		param->player.height = 1;
		param->player.width += 33;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
	
	print_element(&param->canva, param->map, BACKGROUND, &param->background);
	print_element(&param->canva, param->map, EXIT, &param->background);
	print_element(&param->canva, param->map, PLAYER, &param->background);
	print_element(&param->canva, param->map, COINS, &param->background);
	print_element(&param->canva, param->map, WALL, &param->wall);
	print_element(&param->canva, param->map, COINS, &param->coins);
	
	if (key_code == 100)
	{
		printf("entrou\n");
		int i = 0;
		param->exit.width = -32;
		while (i < 4)
		{
			param->exit.x = 15;
			param->exit.y = 10;
			param->exit.width += 33;
			if (param->exit.width >= 133)
			param->exit.width = 1;
			param->exit.height = 1;
			print_element(&param->canva, param->map, EXIT, &param->background);
			print_avatar(&param->canva, param->exit);
			print_avatar(&param->canva, param->player);
			mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
			usleep(100000);
			i++;
		}
	}
	print_avatar(&param->canva, param->player);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
	if (key_code == 65307)
		close_win(param);
	return (0);
}
