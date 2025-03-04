#include "../so_long.h"

void	init_images(t_data *data)
{
	data->canva.img = mlx_new_image(data->mlx, 920, 480);
	data->canva.addr = mlx_get_data_addr(data->canva.img, &data->canva.bits_per_pixel, &data->canva.line_length, &data->canva.endian);
	set_image(&data->background, data->mlx, "./images/background.xpm", &data->background.endian);
	set_image(&data->player.image, data->mlx, "./images/peach.xpm", &data->player.image.endian);
	set_image(&data->wall, data->mlx, "./images/walls.xpm", &data->wall.endian);
	set_image(&data->coins, data->mlx, "./images/coins.xpm", &data->coins.endian);
	set_image(&data->exit.image, data->mlx, "./images/exit.xpm", &data->exit.image.endian);
}
