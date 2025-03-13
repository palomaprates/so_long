#include "../so_long.h"

int	is_map_enclosed(char **lines_map)
{
	int	i;
	int	j;
	int	last_line;
	int	last;
	i = 0;
	j = 0;
	last = ft_strlen(lines_map[i]);
	last_line = get_amount_lines(lines_map) - 1;
	while (j < last)
	{
		if (lines_map[0][j] != '1' || lines_map[last_line][j] != '1')
			return (0);
		j++;
	}
	while (i < last_line)
	{
		if (lines_map[i][0] != '1' || lines_map[i][last - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}