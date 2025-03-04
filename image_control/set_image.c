
#include "../so_long.h"

void	set_image(t_image *image, void *mlx, char *source, int *endian)
{
	image->img = mlx_xpm_file_to_image(mlx,
			source, &image->width, &image->height);
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, endian);
}