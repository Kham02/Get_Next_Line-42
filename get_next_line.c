#include "get_next_line.h"

ft_search()
{
	
}

char ft_read(int fd, char *buf, char *s)
{
	s = read(fd, buf, BUFFER_SIZE);

}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*s;

	if (fd < 0)
		return(0);
	buf = ft_strdup(buf);
	s = ft_read(fd, buf, s);
	if (!s || s[0] == '\0')
	{
		free(s);
		s = 0;
		return(0);
	}

	
	
}