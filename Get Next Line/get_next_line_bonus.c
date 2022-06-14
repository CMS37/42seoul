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

#include "get_next_line_bonus.h"

char	*ft_find_line(int fd, char *backup)
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
			return (NULL);
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
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
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
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[256];

	if (fd < 0 || BUFSIZE <= 0)
		return (NULL);
	backup[fd] = ft_find_line(fd, backup[fd]);
	if (!backup[fd])
	{	
		free(backup[fd]);
		return (NULL);
	}
	line = ft_make_line(backup[fd]);
	backup[fd] = ft_left_line(backup[fd]);
	return (line);
}
