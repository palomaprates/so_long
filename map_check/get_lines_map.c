#include "../so_long.h"

char	**get_lines_map(int fd)
{
	int	i;
	i = 0;
	char *str;
	char *map;
	char **lines_map;
	map = NULL;
	str = get_next_line(fd);
	while(str)
	{
		map = ft_strjoin(map, str);
		str = get_next_line(fd);
		i++;
	}
	lines_map = ft_split(map, '\n');
	return (lines_map);
}