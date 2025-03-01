#include "../so_long.h"

void	init_images(t_data *data)
{
	data->canva.img = mlx_new_image(data->mlx, 920, 480);
	data->canva.addr = mlx_get_data_addr(data->canva.img, &data->canva.bits_per_pixel, &data->canva.line_length, &data->canva.endian);
	data->background.img = mlx_xpm_file_to_image(data->mlx, "./images/background.xpm", &data->background.width, &data->background.height);
	data->background.addr = mlx_get_data_addr(data->background.img, &data->background.bits_per_pixel, &data->background.line_length, &data->background.endian);
	data->player.image.img = mlx_xpm_file_to_image(data->mlx, "./images/peach.xpm", &data->player.width, &data->player.height);
	data->player.image.addr = mlx_get_data_addr(data->player.image.img, &data->player.image.bits_per_pixel, &data->player.image.line_length, &data->player.image.endian);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "./images/walls.xpm", &data->wall.width, &data->wall.height);
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bits_per_pixel, &data->wall.line_length, &data->wall.endian);
	data->coins.img = mlx_xpm_file_to_image(data->mlx, "./images/coins.xpm", &data->coins.width, &data->coins.height);
	data->coins.addr = mlx_get_data_addr(data->coins.img, &data->coins.bits_per_pixel, &data->coins.line_length, &data->coins.endian);
	data->exit.image.img = mlx_xpm_file_to_image(data->mlx, "./images/mario_exit1.xpm", &data->exit.width, &data->exit.height);
	data->exit.image.addr = mlx_get_data_addr(data->exit.image.img, &data->exit.image.bits_per_pixel, &data->exit.image.line_length, &data->exit.image.endian);
}
