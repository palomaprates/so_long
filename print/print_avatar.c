#include "../so_long.h"

	void	print_avatar(t_image *canva, t_sprite player)
{
	int	index_x;
	int	index_y;
	int	pixel;

	index_y = 0;
	while (index_y < 32)
	{
		index_x = 0;
		while (index_x < 32)
		{
			pixel = get_pixel_canva(&player.image, player.width + index_x,
				player.height + index_y);
			if (pixel != -16777216 && pixel != 0)
			{
				my_mlx_pixel_put(canva, (player.x + index_x),
					(player.y + index_y), pixel);
			}
			index_x++;
		}
		index_y++;
	}
}
