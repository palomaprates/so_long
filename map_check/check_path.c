#include "../so_long.h"

static void	dfs(t_map *map, int x, int line)
{
	if (map->flag && map->collectibles == 0)
	{
		printf("map flag inicio %d\n", map->flag);
		return ;
	}
	if (map->map[line][x] == WALL || map->map[line][x] == PLAYER)
		return ;
	if (map->map[line][x] == COINS)
		map->collectibles = map->collectibles - 1;
	if (map->map[line][x] == BACKGROUND || map->map[line][x] == COINS)
		map->map[line][x] = PLAYER;
	if (map->map[line][x] == EXIT)
		map->flag = map->flag + 1;
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
	printf("map collectibles %d\n", map.collectibles);
	map.flag = 0;
	x = x / PLAYER_VELOCITY;
	line = line / PLAYER_VELOCITY;
	dfs(&map, x + 1, line);
	dfs(&map, x - 1, line);
	dfs(&map, x, line + 1);
	dfs(&map, x, line - 1);
	printf("x %d, line %d\n", x, line);
	if (map.flag && map.collectibles == 0)
	{
		printf("map flag %d\n", map.flag);
		printf("map collectibles %d\n", map.collectibles);
		return (1);
	}
	else
		return (0);
}