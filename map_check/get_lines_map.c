#include "../so_long.h"

char	**get_lines_map(int fd)
{
	char *str;
	char *map;
	char **lines_map;
	map = NULL;
	str = get_next_line(fd);
	while(str)
	{
		map = ft_strjoin(map, str);
		str = get_next_line(fd);
	}
	lines_map = ft_split(map, '\n');
	return (lines_map);
}