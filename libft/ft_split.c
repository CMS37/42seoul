/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:03:25 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/15 04:34:37 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strcheck(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	strcpy1(char *arr, char *src, char *charset)
{
	int	i;

	i = 0;
	while (strcheck(src[i], charset) == 1)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
}

int	arrlen(char *str, char *charset)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if ((strcheck(str[i], charset)))
			cnt++;
		i++;
	}
	return (cnt);
}

void	str_end(char **arr, char *charset, char *str)
{
	int	i;
	int	j;
	int	m;

	m = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (strcheck(str[i], charset) == 0)
			i++;
		else
		{
			j = 0;
			while (strcheck(str[i + j], charset) == 1)
				j++;
			arr[m] = (char *)malloc(sizeof(char) * (j + 1));
			strcpy1(arr[m], str + i, charset);
			i += j;
			m++;
		}
	}
	arr[m] = (char *)malloc(sizeof(char));
	arr[m] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (arrlen(str, charset) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	if (str[i] != 0)
	{
		if (*charset == '\0')
		{
			arr[0] = (char *)malloc(sizeof(char) * arrlen(str, charset) + 1);
			while (str[i])
			{
				arr[0][i] = str[i];
				i++;
			}
			arr[0][i] = '\0';
			arr[1] = (char *)malloc(sizeof(char));
			arr[1] = 0;
			return (arr);
		}
		str_end(arr, charset, str);
	}
	return (arr);
}
