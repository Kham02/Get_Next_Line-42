#include "get_next_line.h"

int	main()
{
	char	*line;
	int		fd;

	fd = open("test_text.txt", O_RDONLY);
	get_next_line(fd);
	printf("%s\n", &line);
	return(0);
}
