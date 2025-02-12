#ifndef SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*===============UTILS=============*/

static int	count_words(char const *s, char c);

static void	ft_free(char **new_str, int j);

char	**ft_split(char const *s, char c);

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

int	ft_strlen(char *str);

char	*get_next_line(int fd);

void	to_clear_buffer(char *s1);

int	to_find_newline(char *str);

/*=============MAP CHECK============*/

int	get_amount_lines(char **lines_map);

char	**get_lines_map(int fd);

int	is_map_enclosed(char **lines_map);

int	is_retangular_map(char **lines_map);

int	number_of_elements(char **lines_map, char c);

int	parsing_map(char **lines_map);

#endif