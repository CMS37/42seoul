/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:33:43 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/13 19:33:43 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len_s1;
	int len_s2;
	int	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(set);
	i = 0;
	while (i < len_s1)
	{
		if(s1[i] == set[0])
			return(ft_strnstr(s1, set, len_s2));
		i++;
	}
	return ((char *)s1);
}
/*
#include <stdio.h>

int main()
{
	char	*s1 = "cutHellocut";
	char	*s2 = "cut";
	char	*s3;

	s3 = ft_strtrim(s1, s2);

	printf("%s", s3);
}
*/