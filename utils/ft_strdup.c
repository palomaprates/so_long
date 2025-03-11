#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}