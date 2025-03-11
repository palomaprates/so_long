#include "../so_long.h"

int	parsing_map(t_data data)
{
	if (!is_retangular_map(data.map))
	{
		printf("mapa não é retangular\n");
		return (0);
	}
	if (!*data.map)
		return (0);
	if (!is_map_enclosed(data.map))
	{
		printf("mapa não está fechado\n");
		return (0);
	}
	if (number_of_elements(data.map, 'E') != 1)
	{
		printf("há mais de uma saída\n");
		return (0);
	}
	if (number_of_elements(data.map, 'P') != 1)
	{
		printf("há mais de uma posição inicial\n");
		return (0);
	}
	if (number_of_elements(data.map, 'C') < 1)
	{
		printf("não há coletáveis");
		return (0);
	}
	if (!check_path(data, data.player.x,
		data.player.y))
	{
		printf("There are an invalid path\n");
		return (0);
	}
	return (1);
}
