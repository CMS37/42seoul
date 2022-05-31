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

	if (!backup)
		return (NULL);
	i = 0;
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
		line[i] = backup[i];
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_left_line(char *backup)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	if (!backup)
		return (NULL);
	while(backup[i] && backup[i] != '\n')
		i++;
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
	static char	*backup[4096];

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
	int		fd2;
	int		fd3;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/