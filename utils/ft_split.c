#include "../so_long.h"

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