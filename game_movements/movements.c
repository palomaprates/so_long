#include "../so_long.h"

void	move_up(int key_code, t_data *param)
{
	char *next_pos;
	if (key_code == 119)
	{
		next_pos = touch_element(param->player.x, param->player.y - SQUARE_SIZE, param->map);
		if(*next_pos != WALL)
		param->player.y -= SQUARE_SIZE;
		param->player.height = 66;
		param->player.width += 30;
		if (param->player.width >= 60)
		param->player.width = 1;
	}
}

void	move_down(int key_code, t_data *param)
{
	char *next_pos;
	if (key_code == 115)
	{
		next_pos = touch_element(param->player.x, param->player.y + SQUARE_SIZE, param->map);
		if(*next_pos != WALL)
			param->player.y += SQUARE_SIZE;
		param->player.height = 98;
		if (param->player.width >= 30)
			param->player.width = 1;
	}
}
void	move_left(int key_code, t_data *param)
{
	char *next_pos;
	if (key_code == 97)
	{
		next_pos = touch_element(param->player.x - SQUARE_SIZE, param->player.y, param->map);
		if(*next_pos != WALL)
		param->player.x -= SQUARE_SIZE;
		param->player.height = 34;
		param->player.width += 30;
		if (param->player.width >= 60)
		param->player.width = 1;
	}
}

void	move_right(int key_code, t_data *param)
{
	char *next_pos;
	if (key_code == 100)
	{
		next_pos = touch_element(param->player.x + SQUARE_SIZE, param->player.y, param->map);
		if(*next_pos != WALL)
			param->player.x += SQUARE_SIZE;
		param->player.height = 1;
		param->player.width += 30;
		if (param->player.width >= 60)
			param->player.width = 1;
	}
}
void	movements(int key_code, t_data *param)
{
	move_down(key_code, param);
	move_up(key_code, param);
	move_left(key_code, param);
	move_right(key_code, param);
}
