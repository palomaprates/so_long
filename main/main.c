#include "../so_long.h"

int	main(void)
{
	char	*relative_path = "./images/peach1.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 480, "Hello world!");


	canva.img = mlx_new_image(mlx, 920, 480);
	canva.addr = mlx_get_data_addr(canva.img, &canva.bits_per_pixel, &canva.line_length,
								&canva.endian);
	background.img = mlx_new_image(mlx, 920, 480);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length,
								&background.endian);

	player.img = mlx_xpm_file_to_image(mlx, relative_path, &player.width, &player.height);
	player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length, &player.endian);
	
	avatar.x = 920 / 2;
	avatar.y = 480 / 2;
	avatar.width = 1;
	avatar.height = 1;
	print_background();
	mlx_put_image_to_window(mlx, mlx_win, canva.img, 0, 0);
	mlx_hook(mlx_win, ON_KEYDOWN, 1L<<0, move_player, NULL);
	mlx_loop(mlx);
}