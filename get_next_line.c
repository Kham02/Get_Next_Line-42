#include "get_next_line.h"

ft_end(int len, char *buf, char *s)
{

}

char ft_read(int fd, char *buf, char *s)
{
	int	len;

	len = 1;
	while (!ft_strchr(buf, '\n'))
	{
		if (buf[len] == '\0' && buf[len + 1] == '\n')
		{
			s = read(fd, buf, BUFFER_SIZE);
			len++;
		}
		else if (buf[len] == '\0' && buf[len + 1] != '\n')
			s = ft_end(len, buf, s);
	}
	len += 1;
	return(s);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*s;

	if (fd < 0)
		return(0);
	buf = (char *)malloc(sizeof(s));
	if (!buf)
		return(0);
	s = ft_read(fd, buf, s);
	if (!s || s[0] == '\0')
	{
		free(s);
		s = 0;
		return(0);
	}

	
	
}