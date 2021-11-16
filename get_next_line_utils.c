#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = (char *) malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	s2 = (char *) malloc(sizeof(*s) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			s2[j++] = s[i];
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i != n)
	{
		str [i] = '\0';
		i++;
	}
}

