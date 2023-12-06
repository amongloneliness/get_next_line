#include "get_next_line.h"

/*
** Get line from file descriptor for reading.
*/
char	*get_new_line(int fd, char *line)
{
	char	*new_line;
	char	*buffer_line;
	ssize_t	readed_bytes;

	readed_bytes = 1;
	buffer_line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (readed_bytes > 0)
	{
		if (line != (char *) 0 && ft_strchr(line, '\n') != (char *) 0)
			break ;
		readed_bytes = read(fd, buffer_line, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buffer_line);
			return ((char *) 0);
		}
		buffer_line[readed_bytes] = '\0';
		new_line = ft_strjoin(line, buffer_line);
		free(line);
		line = new_line;
	}
	free(buffer_line);
	return (line);
}

/*
** Get line from file descriptor for reading.
*/
int	get_next_line(int fd, char **line)
{
	static char	*next_line;

	if (fd < 1 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_new_line(fd, next_line);
	if (next_line == (char *) 0)
		return (0);
	*line = get_sub_line(next_line);
	next_line = update_line(next_line);
	return (1);
}
