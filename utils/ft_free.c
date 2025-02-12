#include "../so_long.h"

static void	ft_free(char **new_str, int j)
{
	while (j > 0)
		free(new_str[j--]);
	free(new_str);
}