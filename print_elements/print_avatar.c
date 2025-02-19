#include "../so_long.h"

void	print_avatar(t_image *canva, t_data data)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y < 32)
	{
		index_x = 0;
		while (index_x < 32)
		{
			if (get_pixel_canva(&data.player, data.avatar.width + index_x,
					data.avatar.height + index_y) != -16777216)
			{
				my_mlx_pixel_put(canva, (data.avatar.x + index_x),
					(data.avatar.y + index_y),
					get_pixel_canva(&data.player, data.avatar.width + index_x,
						data.avatar.height + index_y));
			}
			index_x++;
		}
		index_y++;
	}
}