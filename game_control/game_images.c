#include "../so_long.h"

void	game_images(t_data *param)
{
	char *next_pos;
	
	print_element(&param->canva, param->map, BACKGROUND, &param->background);
	print_element(&param->canva, param->map, EXIT, &param->background);
	print_element(&param->canva, param->map, PLAYER, &param->background);
	print_element(&param->canva, param->map, COINS, &param->background);
	print_element(&param->canva, param->map, COINS, &param->coins);
	next_pos = touch_element(param->player.x, param->player.y, param->map);
	if (*next_pos == COINS)
		*next_pos = BACKGROUND;
	print_exit(param);
	if (*next_pos == EXIT && !number_of_elements(param->map, COINS))
			exit(1);
	print_avatar(&param->canva, param->player);
	print_element(&param->canva, param->map, WALL, &param->wall);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
}
