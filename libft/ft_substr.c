/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:59:12 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/10 23:59:12 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len2;

	len2 = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (0);
	if (len2 < start)
	{
		str = "";
		return (str);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}


#include <stdio.h>

int main()
{
	char	*str1 = "i want copy this word";
	char	*str2;

	str2 = ft_substr(str1, 7, 6);
	printf("%s", str2);

	free(str2);

	return (0);
}
