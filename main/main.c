#include "../so_long.h"




int	main(void)
{
	char	*relative_path = "./images/peach1.xpm";
	t_data	data;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 920, 480, "So Long");

	data.canva.img = mlx_new_image(data.mlx, 920, 480);
	data.canva.addr = mlx_get_data_addr(data.canva.img, &data.canva.bits_per_pixel, &data.canva.line_length,
								&data.canva.endian);
	data.background.img = mlx_new_image(data.mlx, 920, 480);
	data.background.addr = mlx_get_data_addr(data.background.img, &data.background.bits_per_pixel, &data.background.line_length,
								&data.background.endian);

	data.player.img = mlx_xpm_file_to_image(data.mlx, relative_path, &data.player.width, &data.player.height);
	data.player.addr = mlx_get_data_addr(data.player.img, &data.player.bits_per_pixel, &data.player.line_length, &data.player.endian);
	
	data.avatar.x = 920 / 2;
	data.avatar.y = 480 / 2;
	data.avatar.width = 1;
	data.avatar.height = 1;

	print_background(&data.canva);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.canva.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L<<0, move_player, &data);
	mlx_loop(data.mlx);
}