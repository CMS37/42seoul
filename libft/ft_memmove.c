/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:22:22 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/20 00:10:09 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const char		*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
		while (n--)
			*d++ = *s++;
	else
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
/*
* src 의 주소가 dest 보다 큰 값이면,
* src 의 처음 부터 count 만큼 dest 에 복사한다.
* src를 한 byte씩 복사하더라도 dest 보다 큰 위치에 있기 때문에,
* 오버랩되더라도 src 를 모두 정상적으로 dest에 복사할수 있다.
*/
/*
* src의 주소가 dest 보다 작은 값이면,
* src 의 마지막 데이터부터 한바이트씩 dest의 마지막 바이트부터
* 순서대로 복사한다.
*/
