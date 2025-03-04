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

int	keys_hook(int key_code, t_data *param)
{
	char *next_pos;
	int i;
	if (key_code == 115)
	{
		next_pos = touch_element(param->player.x, param->player.y + PLAYER_VELOCITY, param->map);
		if(*next_pos != WALL)
			param->player.y += PLAYER_VELOCITY;
		param->player.height = 98;
		if (param->player.width >= 30)
			param->player.width = 1;
	}
	if (key_code == 119)
	{
		next_pos = touch_element(param->player.x, param->player.y - PLAYER_VELOCITY, param->map);
		if(*next_pos != WALL)
			param->player.y -= PLAYER_VELOCITY;
		param->player.height = 66;
		param->player.width += 30;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
	if (key_code == 97)
	{
		next_pos = touch_element(param->player.x - PLAYER_VELOCITY, param->player.y, param->map);
		if(*next_pos != WALL)
			param->player.x -= PLAYER_VELOCITY;
		param->player.height = 34;
		param->player.width += 30;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
	if (key_code == 100)
	{
		next_pos = touch_element(param->player.x + PLAYER_VELOCITY, param->player.y, param->map);
		if(*next_pos != WALL)
			param->player.x += PLAYER_VELOCITY;
		param->player.height = 1;
		param->player.width += 30;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
	print_element(&param->canva, param->map, BACKGROUND, &param->background);
	print_element(&param->canva, param->map, EXIT, &param->background);
	print_element(&param->canva, param->map, PLAYER, &param->background);
	print_element(&param->canva, param->map, COINS, &param->background);
	print_element(&param->canva, param->map, COINS, &param->coins);

	next_pos = touch_element(param->player.x, param->player.y, param->map);
	 if (*next_pos == COINS)
		*next_pos = BACKGROUND;
	
	if (*next_pos == EXIT && !number_of_elements(param->map, COINS))
			exit(1);
	print_exit(param);
	print_avatar(&param->canva, param->player);
	print_element(&param->canva, param->map, WALL, &param->wall);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
	if (key_code == 65307)
		close_win(param);
	return (0);
}
