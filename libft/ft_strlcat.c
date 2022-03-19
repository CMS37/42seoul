/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:12:00 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/14 22:12:00 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_s;
	size_t	d_s;

	s_s = ft_strlen(src);
	d_s = ft_strlen(dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	if (d_s < size)
		return (d_s + s_s);
	return (size + s_s);
}
