/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:11:07 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/14 18:00:41 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	d = dest;
	s = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (0);
	while (i++ < n)
		*d++ = *s++;
	return (dest);
}
