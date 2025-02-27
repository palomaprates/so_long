#include "../so_long.h"


int	destroy_hook(t_data *data)
{
	close_win(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int fd = open("map.ber", O_RDONLY);
	data.map = get_lines_map(fd);
	int height_win;
	int width_win;
	if (!parsing_map(data.map))
		return (0);
	height_win = get_amount_lines(data.map) * 20;
	width_win = ft_strlen(data.map[0]) * 20;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, width_win, height_win, "So Long");
	init_images(&data);
	data.avatar.x = width_win / 2;
	data.avatar.y = height_win / 2;
	data.avatar.width = 1;
	data.avatar.height = 1;
	print_background(&data.canva);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.canva.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L<<0, keys_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L<<2, destroy_hook, &data);
	mlx_loop(data.mlx);
}