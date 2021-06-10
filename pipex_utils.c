#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{	
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*p;
	int		size;
	int		b;
	int		i;

	if (dst == 0 || src == 0)
		return (0);
	i = -1;
	size = ft_strlen((char *)dst) + ft_strlen((char *)src) + 1;
	p = malloc(size * sizeof(char));
	while (dst[++i] != '\0')
		p[i] = dst[i];
	b = 0;
	while (src[b] != '\0')
	{
		p[i] = src[b];
		i++;
		b++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((ss1[i] != '\0' || ss2[i] != '\0') && (ss1[i] == ss2[i]) && (i < n))
	{
		i++;
	}
	if (i == n)
		i--;
	if (ss1[i] != ss2[i])
	{
		return (ss1[i] - ss2[i]);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		a;

	i = 0;
	a = ft_strlen(s);
	while (i <= a)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
