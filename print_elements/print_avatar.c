#include "../so_long.h"

void	print_avatar(t_image *canva)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y < 32)
	{
		index_x = 0;
		while (index_x < 32)
		{
			printf("pixel: %d\n", get_pixel_canva(&player, avatar.width + index_x,
					avatar.height + index_y));
			if (get_pixel_canva(&player, avatar.width + index_x,
					avatar.height + index_y) != -16777216)
			{
				my_mlx_pixel_put(canva, (avatar.x + index_x),
					(avatar.y + index_y),
					get_pixel_canva(&player, avatar.width + index_x,
						avatar.height + index_y));
			}
			index_x++;
		}
		index_y++;
	}
}