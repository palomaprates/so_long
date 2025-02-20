#include "../so_long.h"

void	print_walls(t_image *canva, t_data *data)
{
	int	line; 
	int	length;

	line = 0;
	while(data->map[line])
	{
		length = 0;
		while(data->map[line][length])
		{
			if (data->map[line][length] == '1')
				print_image(canva, &data->wall, (length * 32), (line * 32));
			length++;
		}
		line++;
	}
}


