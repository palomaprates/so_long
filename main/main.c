#include "../so_long.h"

int	destroy_hook(t_data *data)
{
	close_win(data);
	return (0);
}
int	main(int argc, char *argv[])
{
	t_data	data;
	int fd = open(argv[1], O_RDONLY);
	int height_win;
	int width_win;
	data.map = get_lines_map(fd);
	height_win = get_amount_lines(data.map) * SIZE;
	width_win = ft_strlen(data.map[0]) * SIZE;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, width_win, height_win, "So Long");
	init_images(&data);
	data.collectibles = number_of_elements(data.map, COINS);
	get_avatar_position(&data.player, &data.exit, data.map);
	if (!parsing_map(data))
		return (0);
	printf(" A %d\n", data.exit.x);
	printf(" B %d\n", data.exit.y);
	data.player.width = 1;
	data.player.height = 1;
	data.exit.width = 1;
	data.exit.height = 1;
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.canva.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L<<0, keys_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L<<2, destroy_hook, &data);
	mlx_loop(data.mlx);
}
