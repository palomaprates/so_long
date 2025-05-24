#include "../so_long.h"

static void	ft_free(char **new_str, int j)
{
	while (j > 0)
		free(new_str[j--]);
	free(new_str);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if ((s[i + 1] == c && s[i] != c)
			|| (s[i + 1] == '\0' && s[i] != c))
			j++;
		i++;
	}
	return (j);
}
char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		words_nbr;
	int		i;
	int		j;

	words_nbr = count_words(s, c);
	new_str = malloc(sizeof(char *) * (words_nbr + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	i = 0;
	while (j < words_nbr)
	{
		while (s[i] && s[i] == c)
			i++;
		s = s + i;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		new_str[j] = malloc(sizeof(char) * (i + 1));
		if (!new_str[j])
			return (ft_free(new_str, j), NULL);
		ft_strlcpy(new_str[j++], s, ++i);
	}
	return (new_str[j] = NULL, new_str);
}
