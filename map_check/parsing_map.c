#include "../so_long.h"

int	parsing_map(char **lines_map)
{
	if (!is_retangular_map(lines_map))
		return (printf("mapa não é retangular"));
	if (!*lines_map)
		return (0);
	if (!is_map_enclosed(lines_map))
	{
		printf("mapa não está fechado");
		return (0);
	}
	if (number_of_elements(lines_map, 'E') != 1)
	{
		printf("há mais de uma saída");
		return (0);
	}
	if (number_of_elements(lines_map, 'P') != 1)
	{
		printf("há mais de uma posição inicial");
		return (0);
	}
	if (number_of_elements(lines_map, 'C') < 1)
	{
		printf("não há coletáveis");
		return (0);
	}
	return (1);
}
