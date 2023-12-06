#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> 
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*
** Get special line from file descriptor for reading.
*/
int		get_next_line(int fd, char **line);
/*
** Get line from file descriptor for reading.
*/
char	*get_new_line(int fd, char *line);
/*
** Get the part of the string up to the '\n' character.
*/
char	*get_sub_line(const char *line);
/*
** Shift a line to the right and delete the left part.
*/
char	*update_line(char *line);
/*
** Determine the length of a fixed-size string.
*/
size_t	ft_strlen(const char *s);
/*
** Allocates memory and gets a new code, which is
** the basis of the union of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2);
/*
** Searches for the first occurence of the character in the string.
*/
char	*ft_strchr(const char *s, int c);

#endif