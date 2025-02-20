#include "../so_long.h"


int	destroy_hook(t_data *data)
{
	close_win(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	int fd = open("map.ber", O_RDONLY);
	char **map = get_lines_map(fd);
	if (!parsing_map(map))
			return (0);
	t_data	data;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 920, 480, "So Long");
	init_images(&data);
	data.avatar.x = 920 / 2;
	data.avatar.y = 480 / 2;
	data.avatar.width = 1;
	data.avatar.height = 1;
	print_background(&data.canva);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.canva.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L<<0, keys_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L<<2, destroy_hook, &data);
	mlx_loop(data.mlx);
}