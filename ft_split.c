#include "pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*s1;
	size_t		size;
	size_t		c;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	i = 0;
	size = len + 1;
	s1 = malloc(size * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	c = start;
	while (s[c] != '\0' && i < len)
	{
		s1[i] = s[c];
		i++;
		c++;
	}
	s1[i] = '\0';
	return (s1);
}

static	size_t	delimc(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		while ((s[i] != c && s[i] != '\0'))
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			n++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (n);
}

static	char	**ft_free(char **p, int j)
{
	while (--j)
		free(&p[j]);
	free(p);
	return (NULL);
}

char	**ft_split_normal(char *s, char c)
{
	size_t		j;
	size_t		len;
	size_t		start;
	size_t		k;
	char		**p;

	if (s == 0)
		return (0);
	j = delimc(s, c) + 1;
	p = (char **)malloc(j * sizeof(char *));
	k = 0;
	len = 0;
	while (k < j - 1)
	{
		while (s[len] && s[len] == c)
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		p[k++] = ft_substr(s, start, (len - start));
	}
	p[k] = 0;
	return (p);
}
