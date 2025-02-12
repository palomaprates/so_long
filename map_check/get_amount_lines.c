#include "../so_long.h"

int	get_amount_lines(char **lines_map)
{
	int	i;

	i = 0;
	while(lines_map[i])
		i++;
	return(i);
}