/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:03:25 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/25 19:59:02 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	arrlen(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		cnt++;
	return (cnt);
}

size_t	nextend(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;
	size_t	len_arr;

	if (!s)
		return (NULL);
	len_arr = arrlen(s, c);
	arr = (char **)malloc(sizeof(char *) * (len_arr + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_arr)
	{
		while (*s && *s == c)
			s++;
		len = nextend(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (NULL);
		ft_strlcpy(arr[i], s, len + 1);
//		if (i < len_arr)
			s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
