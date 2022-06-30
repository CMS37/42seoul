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

t_list	*ft_list(t_list **start, int fd)
{
	t_list	*node;

	node = *start;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return(NULL);
	node->fd = fd;
	node->line = "\0";
	node->next = *start;
	*start = node;
	return (node);
}

char	*ft_find_line(int fd, char *line)
{
	char	*buf;
	char	*line2;
	int		i;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(line) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		line2 = ft_strdup(line);
		free(line);
		line = ft_strjoin(line2, buf);
		free(line2);
	}
	free (buf);
	return (line);
}

char	*ft_make_line(char *line)
{
	char	*line2;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	line2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!line2)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		line2[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		line2[i] = line[i];
		i++;
	}
	line2[i] = '\0';
	return (line2);
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
	char			*new_line;
	t_list			*line;
	static t_list	*head;

	line = ft_list(&head, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (NULL);
	line->line = ft_find_line(fd, line->line);
	if (!line->line)
		return (NULL);
	new_line = ft_make_line(line->line);
	line->line = ft_left_line(line->line);
	free(line);
	return (new_line);
}
