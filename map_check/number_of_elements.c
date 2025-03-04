#include "../so_long.h"

int	number_of_elements(char **lines_map, char c)
{
	int	i;
	int	j;
	int	count;
	i = 0;
	count = 0;
	while (lines_map[i])
	{
		j = 0;
		while (lines_map[i][j])
		{
			if (lines_map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
