/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:30:01 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/14 18:01:27 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = s;
	i = 0;
	while (i < n)
	{
		*a = c;
		a++;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    long long *str;

    str = malloc(sizeof(long long));
    ft_memset(str, 52, 9);
    printf("0x%llx\n", *str);
    memset(str, 42, 9);
    printf("0x%llx\n", *str);
    memset(str, 52, 9);
    printf("0x%llx\n", *str);

    free(str);

    return (0);
}
*/