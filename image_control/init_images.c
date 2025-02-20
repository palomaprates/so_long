#include "../so_long.h"

void	init_images(t_data *data)
{
	data->canva.img = mlx_new_image(data->mlx, 920, 480);
	data->canva.addr = mlx_get_data_addr(data->canva.img, &data->canva.bits_per_pixel, &data->canva.line_length, &data->canva.endian);
	data->background.img = mlx_new_image(data->mlx, 920, 480);
	data->background.addr = mlx_get_data_addr(data->background.img, &data->background.bits_per_pixel, &data->background.line_length, &data->background.endian);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "./images/peach1.xpm", &data->player.width, &data->player.height);
	data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bits_per_pixel, &data->player.line_length, &data->player.endian);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "./images/walls.xpm", &data->wall.width, &data->wall.height);
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bits_per_pixel, &data->wall.line_length, &data->wall.endian);
}
