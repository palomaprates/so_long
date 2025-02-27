#include "../so_long.h"

void	print_element(t_image *canva, char **map, char c, t_image *img)
{
	int	line; 
	int	length;

	line = 0;
	while(map[line])
	{
		length = 0;
		while(map[line][length])
		{
				if (map[line][length] == c)
						print_image(canva, img, (length * 20), (line * 20));
				length++;
		}
		line++;
	}
}


