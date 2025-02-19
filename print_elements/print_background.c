#include "../so_long.h"

void print_background(t_image *canva)
{
	int j;
	int i;
	j = 0; 
	while (j < 480) 
	{
		i = 0;
		while (i < 920)
		 {
			my_mlx_pixel_put(canva, i, j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}