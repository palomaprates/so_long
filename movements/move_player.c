#include "../so_long.h"

int	move_player(int key_code, void *param)
{
	if (key_code == 115)
	{
		avatar.y += 10;
		avatar.height = 98;
		if (avatar.width >= 32)
			avatar.width = 1;
	}
	if (key_code == 119)
	{
		avatar.y -= 10;
		avatar.height = 66;
		avatar.width += 33;
		if (avatar.width >= 60)
			avatar.width = 1;
		
	}
	if (key_code == 97)
	{
		avatar.x -= 10;
		avatar.height = 34;
		avatar.width += 33;
		if (avatar.width >= 60)
			avatar.width = 1;
	}
	if (key_code == 100)
	{
		avatar.x += 10;
		avatar.height = 1;
		avatar.width += 33;
		if (avatar.width >= 60)
			avatar.width = 1;
	}
		print_background();

	
		// print_image(&canva, &player, x, y);
		print_avatar(&canva);


	mlx_put_image_to_window(mlx, mlx_win, canva.img, 0, 0);
	return (0);
}