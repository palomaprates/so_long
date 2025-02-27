#include "../so_long.h"

int	len_map(char **lines_map)
{
	int	lines;
	int	lines_length;
	
	lines = get_amount_lines(lines_map);
	if (is_retangular_map(lines_map))
		lines_length = ft_strlen(lines_map[0]);
	return (lines * lines_length);
}