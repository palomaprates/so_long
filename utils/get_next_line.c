#include "../so_long.h"

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
