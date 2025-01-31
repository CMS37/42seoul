/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:07:46 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/21 20:48:58 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*a++ = 0;
		i++;
	}
}
/*
int main()
{
    long long *str;

    str = malloc(sizeof(long long));
    printf("0x%llx\n", *str);
    ft_bzero(str, 7);
    printf("0x%llx : ", *str);
    bzero(str, 7);
    printf("0x%llx\n", *str);
	ft_bzero(str, 7);
    printf("0x%llx : ", *str);

    free(str);

    return (0);
}
*/