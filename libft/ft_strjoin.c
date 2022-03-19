/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:22:58 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/13 19:22:58 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
