# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}


//SPLIT
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (dest_size > 0)
	{
		while (src[i] && i < dest_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[src_len])
		src_len++;
	return (src_len);
}

//SPLIT

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
//SPLIT

static void	ft_free(char **new_str, int j)
{
	while (j > 0)
		free(new_str[j--]);
	free(new_str);
}

//SPLIT

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
//GNL
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


//GNL

int	to_find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
//GNL

void	to_clear_buffer(char *s1)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	i = -1;
	while (new[++i])
		s1[i] = new[i];
	s1[i] = '\0';
	free(new);
}
//GNL

char	*get_next_line(int fd)
{
	static char	buffer[2];
	int			read_bytes;
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (*buffer)
	{
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer), line);
	}
	read_bytes = read(fd, buffer, 1);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = 0;
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer), line);
		read_bytes = read(fd, buffer, 1);
	}
	if (*buffer)
		return (to_clear_buffer(buffer), line);
	return (NULL);
}

//SO LONG
char	**get_lines_map(int fd)
{
	int	i;
	i = 0;
	char *str;
	char *map;
	char **lines_map;
	map = NULL;

		str = get_next_line(fd);
	while(str)
	{
		map = ft_strjoin(map, str);
		str = get_next_line(fd);
		i++;
	}
	lines_map = ft_split(map, '\n');
	return (lines_map);
}
int	get_amount_lines(char **lines_map)
{
	int	i;

	i = 0;
	while(lines_map[i])
		i++;
	return(i);
}

int	is_retangular_map(char **lines_map)
{
	int	i;
	int	size;

	i = 0;
	while (lines_map[i])
	{
		if (i > 0)
			if (size != ft_strlen(lines_map[i]))
				return (0);
		size = ft_strlen(lines_map[i]);
		i++;
	}
	return (1);
}
int	is_map_enclosed(char **lines_map)
{
	int	i;
	int	j;
	int	last_line;
	int	last;
	i = 0;
	j = 0;
	last = ft_strlen(lines_map[i]);
	last_line = get_amount_lines(lines_map) - 1;
	printf("last: %d last line: %d\n", last, last_line);
	while(j < last)
	{
		if (lines_map[0][j] != '1' || lines_map[last_line][j] != '1')
			return (0);
		j++;
	}
	while (i < last_line)
	{
		if (lines_map[i][0] != '1' || lines_map[i][last - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	number_of_elements(char **lines_map, char c)
{
	int	i;
	int	j;
	int	count;
	i = 0;
	count = 0;
	while (lines_map[i])
	{
		j = 0;
		while (lines_map[i][j])
		{
			if (lines_map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	parsing_map(char **lines_map)
{
	if (!is_retangular_map(lines_map))
	{
		printf("mapa não é retangular");
		return (0);
	}
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
int	main()
{
	int fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return printf("fd :(\n");
	char **map = get_lines_map(fd);
	if(!parsing_map(map))
		return printf("errado :(\n");
	printf("ok\n");
	return (0);
}