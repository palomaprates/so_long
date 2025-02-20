#include "../so_long.h"

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->canva.img);
}