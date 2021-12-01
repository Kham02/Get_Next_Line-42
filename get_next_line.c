/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:48:01 by estrong           #+#    #+#             */
/*   Updated: 2021/12/01 16:13:40 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before(char	*line)
{
	int		i;
	char	*s1;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	s1 = ft_substr(line, 0, i);
	return (s1);
}

char	*ft_after(char	*line)
{
	int		i;
	char	*s2;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	s2 = ft_substr(line, i, ft_strlen(line));
	free(line);
	return (s2);
}

char	*ft_read(int fd, char *line)
{
	char	*buf;
	int		n;

	n = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (n != 0 && !ft_strchr(line, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(buf);
			return (0);
		}
		buf[n] = '\0';
		if (!line)
			line = ft_substr(buf, 0, n);
		else
			line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = ft_read(fd, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		line = 0;
		return (0);
	}
	s = ft_before(line);
	if (!s || s[0] == '\0')
	{
		free(s);
		return (0);
	}
	line = ft_after(line);
	return (s);
}

int	main()
{
	int		fd;
	char	*s;

	fd = open("test_text.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);
	while(1)
	{
		;
	}
	close(fd);
	return (0);
}