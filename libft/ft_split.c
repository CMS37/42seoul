/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:03:25 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/22 21:15:03 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

size_t	arrlen(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		i++;
	while(s[i])
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
		if (i < len_arr)
			s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

#include <stdio.h>

static void			ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void			ft_print_tabstr(char **tabstr)
{
	int		i;

	i = 0;
	while (tabstr[i] != NULL)
	{
		ft_print_result(tabstr[i]);
		write(1, "\n", 1);
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
}

static void			check_split(char *s, char c)
{
	char	**tabstr;

	if (!(tabstr = ft_split(s, c)))
		ft_print_result("NULL");
	else
		ft_print_tabstr(tabstr);
}

int	main()
{
	printf("1\n");
	check_split("          ", ' ');
	printf("2\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("3\n");
	check_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	printf("4\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	printf("5\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	return (0);
}
