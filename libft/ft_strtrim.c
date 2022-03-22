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
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);		
}


#include <stdio.h>

int main()
{
	char	*s1 = "cutHellocut";
	char	*s2 = "cut";
	char	*s3;

	s3 = ft_strtrim(s1, s2);

	printf("%s", s3);
}
