#include "get_next_line.h"


char	*ft_get_line(char **line, size_t len)
{
	char	*str;
	char	*s2;
	size_t	n;

	if (len < 0)
		return (0);
	if (!len && (!line || !*line))
		return (0);
	n = 0;
	str = NULL;
	while ((*line)[n] != '\n' && (*line)[n])
		n++;
	if ((*line)[n] == '\n')
	{
		str = ft_substr(*line, 0, n + 1);
		s2 = ft_strdup(*line + n + +1);
		free(*line);
		*line = s2;
		if (!**line)
		{
			free(*line);
			*line = NULL;
		}
		return (str);
	}
	str = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*s;
	size_t		len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return(0);
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = '\0';
		if (!line)
			line = ft_strdup("");
		s = ft_strjoin(line, buf);
		free(line);
		line = s;
		if (ft_strchr(buf, '\n'))
			break;
		len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return(ft_get_line(&line, len));
}

int	main()
{
	char	*line;
	int		fd;

	fd = open("test_text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return(0);
}