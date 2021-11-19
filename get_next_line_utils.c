#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return(len);
}

char	*ft_strchr(const char *s, int n)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)n && s[i] != '\0' )
		i++;
	if ((unsigned char)s[i] == (unsigned char)n)
		return ((char *)(&s[i]));
	return (NULL);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s1)
		return (NULL);
	if (!s1)
		return (NULL);
	str = (char *) malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[n++] = s1[i++];
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n] = '\0';
	return (str);
}

