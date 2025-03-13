#include "../so_long.h"

t_map	copy_map(t_data data)
{
	t_map new_map;
	int i;

	new_map.map = malloc(sizeof(char *) * (get_amount_lines(data.map) + 1));
	if (!new_map.map)
		return (new_map);
	i = 0;
	while (data.map[i])
	{
		new_map.map[i] = ft_strdup(data.map[i]);
		if (!new_map.map[i])
		{
			while (--i >= 0)
				free(new_map.map[i]);
			free(new_map.map);
			return (new_map);
		}
		i++;
	}
	new_map.map[i] = NULL;
	new_map.collectibles = data.collectibles;
	new_map.flag = 0;
	return (new_map);
}
