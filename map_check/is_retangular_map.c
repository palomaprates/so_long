#include "../so_long.h"

int	is_retangular_map(char **lines_map)
{
	int	i;
	int	size;

	i = 0;
	while (lines_map[i])
	{
		if (i > 0)
			if (size != ft_strlen(lines_map[i]))
				return (0);
		size = ft_strlen(lines_map[i]);
		i++;
	}
	return (1);
}