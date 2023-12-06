#include "get_next_line.h"

/*
** Get the part of the string up to the '\n' character.
*/
char	*get_sub_line(const char *line)
{
	char	*sub_line;
	size_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	if (len == 0 && line[len] == '\0')
		return ((char *) 0);
	sub_line = (char *) malloc(sizeof(char) * (len + 2));
	sub_line[len + 1] = '\0';
	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
	{
		sub_line[len] = line[len];
		len++;
	}
	if (line[len] == '\n')
	{
		sub_line[len] = line[len];
		len++;
	}
	sub_line[len] = '\0';
	return (sub_line);
}

/*
** Shift a line to the right and delete the left part.
*/
char	*update_line(char *line)
{
	size_t	index;
	size_t	start;
	size_t	len;
	char	*sub_line;

	start = 0;
	while (line[start] != '\0' && line[start] != '\n')
		start++;
	if (line[start] == '\0')
	{
		free(line);
		return ((char *) 0);
	}
	len = ft_strlen(line) - start;
	start++;
	if (len > 0)
	{
		index = 0;
		sub_line = (char *) malloc(sizeof(char) * (len + 1));
		sub_line[len] = '\0';
		while (index < len)
			sub_line[index++] = line[start++];
	}
	free(line);
	return (sub_line);
}

/*
** Determine the length of a fixed-size string.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

/*
** Searches for the first occurence of the character in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	while ((int) *s != c && *s != '\0')
		s++;
	if (*s == (char) c)
		return ((char *) s);
	else
		return ((char *) 0);
}

/*
** Allocates memory and gets a new code, which is
** the basis of the union of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	len;
	size_t	index;

	len = 0;
	index = 0;
	if (s1 == (char *) 0 && s2 == (char *) 0)
		return ((char *) 0);
	if (s1 != (char *) 0)
		len += ft_strlen(s1);
	if (s2 != (char *) 0)
		len += ft_strlen(s2);
	res_str = (char *) malloc(sizeof(char) * (len + 1));
	res_str[len] = '\0';
	if (s1 != (char *) 0)
	{
		while (*s1 != '\0')
			res_str[index++] = *s1++;
	}
	if (s2 != (char *) 0)
	{
		while (*s2 != '\0')
			res_str[index++] = *s2++;
	}
	return (res_str);
}
