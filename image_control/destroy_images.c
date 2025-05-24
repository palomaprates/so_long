#include "../so_long.h"

void	destroy_images(t_data *data)
{
	
    mlx_destroy_image(data->mlx, data->background.img);
    mlx_destroy_image(data->mlx, data->wall.img);
    mlx_destroy_image(data->mlx, data->canva.img);
    mlx_destroy_image(data->mlx, data->coins.img);
    mlx_destroy_image(data->mlx, data->player.image.img);
    mlx_destroy_image(data->mlx, data->exit.image.img);
}