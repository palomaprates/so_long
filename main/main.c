#include "../so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

	void	*mlx;
	void	*mlx_win;
	t_data	background;
	t_data	player;


	int	x = 920 / 2;
	int	y =  480 / 2;

	enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_background()
{
	for (int j = 0; j < 480; j++) 
	{
		for (int i = 0; i < 920; i++) {
			my_mlx_pixel_put(&background, i, j, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, background.img, 0, 0);
}
int	move_player(int key_code, void *param)
{
	char	*relative_path = "./images/peach.xpm";

		print_background();
	if (key_code == 115)
	{
		y += 10;
	}
	if (key_code == 119)
	{
		y -= 10;
	}
	if (key_code == 97)
	{
		x -= 10;
	}
	if (key_code == 100)
	{
		x += 10;
	}
		print_background();

		player.img = mlx_xpm_file_to_image(mlx, relative_path, &player.width, &player.height);
	mlx_put_image_to_window(mlx, mlx_win, player.img, x, y);

	return (0);
}

int	main(void)
{
	char	*relative_path = "./images/peach.xpm";
	int		img_width;
	int		img_height;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 480, "Hello world!");
	background.img = mlx_new_image(mlx, 920, 480);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length,
								&background.endian);
	player.img = mlx_new_image(mlx, 920, 480);
		player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length,
									&player.endian);
	print_background();
	mlx_hook(mlx_win, ON_KEYDOWN, 1L<<0, move_player, NULL);
	mlx_loop(mlx);
}