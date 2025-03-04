#include "../so_long.h"

int	parsing_map(char **lines_map)
{
	if (!is_retangular_map(lines_map))
		return (printf("mapa não é retangular"));
	if (!*lines_map)
		return (0);
	if (!is_map_enclosed(lines_map))
		return (printf("mapa não está fechado"));
	if (number_of_elements(lines_map, 'E') != 1)
		return (printf("há mais de uma saída"));
	if (number_of_elements(lines_map, 'P') != 1)
		return (printf("há mais de uma posição inicial"));
	if (number_of_elements(lines_map, 'C') < 1)
		return (printf("não há coletáveis"));
	return (1);
}
