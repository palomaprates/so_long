#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		totalsize;
	int		i;
	int		j;

	i = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (totalsize + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		if (++i && s2[j++] == '\n')
			break ;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}
