#include "../so_long.h"

int	main()
{
	int fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return printf("fd :(\n");
	char **map = get_lines_map(fd);
	if(!parsing_map(map))
		return printf("errado :(\n");
	printf("ok\n");
	return (0);
}