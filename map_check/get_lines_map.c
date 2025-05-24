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
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (!map)
		return (NULL);
	lines_map = ft_split(map, '\n');
	free(map);
	return (lines_map);
}