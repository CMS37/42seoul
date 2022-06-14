/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:45:22 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/28 19:45:22 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFSIZE 1

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_find_line(int fd, char *backup);
char	*ft_make_line(char *backup);
char	*ft_left_line(char *backup);
char	*ft_strchr(char	*str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

#endif