/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:44:41 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/28 19:44:41 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFSIZE 4

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}

char	*ft_strchr(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	if (str[i] == '\0')
		return ((char *)(str + i));
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char    *ft_find_line(int fd, char *backup)
{
	char	*buf;
	int		i;

	
	buf = (char *)malloc((BUFSIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(backup) && i != 0)
	{
		i = read(fd, buf, BUFSIZE);
		if (i == -1)
		{
			free(buf);
			return(NULL);
		}
		buf[i] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free (buf);
	return (backup);
}

char	*ft_make_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_left_line(char *backup)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	while(backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
	{
		str[j] = backup[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(backup);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[1000];

	if (fd < 0 || BUFSIZE <= 0)
		return (NULL);
	backup[fd] = ft_find_line(fd, backup[fd]);
	if (!backup[fd])
		return(NULL);
	line = ft_make_line(backup[fd]);
	backup[fd] = ft_left_line(backup[fd]);
	return (line);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line [%02d]:%s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/