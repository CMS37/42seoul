/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:03:12 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/12 19:03:12 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && (i + j) < n)
			{
				j++;
				if (s2[j] == '\0')
					return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1 = "lorem ipsum dolor sit amet";
	char	*str2 = "dolor";
	char	*find;

	find = ft_strnstr(str1, str2, 20);
	printf("%s", find);
	return (0);
}
*/