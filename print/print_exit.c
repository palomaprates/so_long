#include "../so_long.h"

void	print_exit(t_data *param)
{
	if (!number_of_elements(param->map, COINS))
		print_element(&param->canva, param->map, EXIT, &param->exit.image);
}
