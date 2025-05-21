#include "../so_long.h"

static void	dfs(t_map *map, int x, int line)
{
	if (map->flag && map->collectibles == 0)
		return ;
	if (map->map[line][x] == WALL || map->map[line][x] == PLAYER)
		return ;
	if (map->map[line][x] == COINS)
		map->collectibles = map->collectibles - 1;
	if (map->map[line][x] == BACKGROUND || map->map[line][x] == COINS)
		map->map[line][x] = PLAYER;
	if (map->map[line][x] == EXIT && map->flag == 0)
		map->flag = map->flag + 1;
	map->map[line][x] = PLAYER;
	dfs(map, x + 1, line);
	dfs(map, x - 1, line);
	dfs(map, x, line + 1);
	dfs(map, x, line - 1);
}

int	check_path(t_data data, int x, int line)
{
	t_map	map;
	map = copy_map(data);
	map.collectibles = data.collectibles;
	map.flag = 0;
	x = x / SQUARE_SIZE + 1;
	line = line / SQUARE_SIZE + 1;
	ft_printf("check path x %d\n", x);
	ft_printf("check path line %d\n", line);
	dfs(&map, x + 1, line);
	dfs(&map, x - 1, line);
	dfs(&map, x, line + 1);
	dfs(&map, x, line - 1);
	if (map.flag && map.collectibles == 0)
		return (1);
	else
		return (0);
}
